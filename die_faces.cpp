#include    "die_faces.h"
#include    <cstdlib>
#include    <cmath>
#include    <malloc.h>
#include    <opencv2/core.hpp>
#ifndef ARRAYSIZE
#define ARRAYSIZE(a)    sizeof(a)/sizeof(a[0])
#endif

static float distance(const cv::Point2f& p0, const cv::Point2f& p1)
{
    cv::Point2f dif = p0 - p1;
    return std::sqrt(dif.x*dif.x + dif.y*dif.y);
}

static const cv::Vec4b color_bg(220, 220, 220, 255); // light gray
static const cv::Vec4b color_dot(0, 0, 255, 255); // red
static const cv::Vec4b color_dot2(0, 0, 0, 255); // black
static const cv::Vec4b color_cm(255, 0, 0, 255); // blue

int CreateSquare1(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf)
{
    int err = EXIT_SUCCESS;
    do {
        int area = edge_length * edge_length;
        int cb_alloc = 4*area;
        cv::Vec4b* i_buf = (cv::Vec4b*)(*ppbuf = (unsigned char*)malloc(cb_alloc));
        if (i_buf == nullptr)
        {
            err = EXIT_FAILURE;
            break;
        }

        cv::Point2f center(edge_length*0.5f, edge_length*0.5f);
        float dotR = conf->relative_dotR1 * edge_length;
        float corner_mark_border = conf->relative_margin * edge_length;
        for (int iy = 0; iy != edge_length; iy++)
        {
            for (int ix = 0; ix != edge_length; ix++)
            {
                *i_buf = color_bg;
                cv::Point2f p((float)ix, (float)iy);
                float dist = distance(p, center);
                if (dist < dotR)
                {
                    *i_buf = color_dot;
                }
                else if ((ix + iy) < corner_mark_border)
                {
                    *i_buf = color_cm;
                }
                *i_buf++;
            }
        }
    } while (0);
    return err;
}

int CreateSquare2(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf)
{
    int err = EXIT_SUCCESS;
    do {
        int area = edge_length * edge_length;
        int cb_alloc = 4*area;
        cv::Vec4b* i_buf = (cv::Vec4b*)(*ppbuf = (unsigned char*)malloc(cb_alloc));
        if (i_buf == nullptr)
        {
            err = EXIT_FAILURE;
            break;
        }

        cv::Point2f centers[2];
        centers[0] = cv::Point2f(
            (conf->relative_margin + conf->relative_dotR) * edge_length,
            (1.0f - (conf->relative_margin + conf->relative_dotR)) * (edge_length-1)
        );
        centers[1] = cv::Point2f(centers[0].y, centers[0].x);
        float dotR = conf->relative_dotR * edge_length;
        float corner_mark_border = conf->relative_margin * edge_length;
        for (int iy = 0; iy != edge_length; iy++)
        {
            for (int ix = 0; ix != edge_length; ix++)
            {
                cv::Point2f p((float)ix, (float)iy);
                *i_buf = color_bg;
                for (int i_center = 0; i_center != 2; i_center++)
                {
                    if (distance(centers[i_center], p) < dotR)
                    {
                        *i_buf = color_dot2;
                    }
                }
                if ((ix + iy) < corner_mark_border)
                {
                    *i_buf = color_cm;
                }
                i_buf++;
            }
        }
    } while (0);
    return err;
}

int CreateSquare3(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf)
{
    int err = EXIT_SUCCESS;
    do {
        int area = edge_length * edge_length;
        int cb_alloc = 4*area;
        cv::Vec4b* i_buf = (cv::Vec4b*)(*ppbuf = (unsigned char*)malloc(cb_alloc));
        if (i_buf == nullptr)
        {
            err = EXIT_FAILURE;
            break;
        }

        cv::Point2f centers[3];
        centers[0] = cv::Point2f(
            (conf->relative_margin + conf->relative_dotR) * edge_length,
            (conf->relative_margin + conf->relative_dotR) * edge_length
        );
        centers[1] = cv::Point2f(0.5f * edge_length, 0.5f * edge_length);
        centers[2] = cv::Point2f(
            (1.0f - (conf->relative_margin + conf->relative_dotR)) * (edge_length-1),
            (1.0f - (conf->relative_margin + conf->relative_dotR)) * (edge_length-1)
        );
        float dotR = conf->relative_dotR * edge_length;
        float corner_mark_border = conf->relative_margin * edge_length;
        for (int iy = 0; iy != edge_length; iy++)
        {
            for (int ix = 0; ix != edge_length; ix++)
            {
                cv::Point2f p((float)ix, (float)iy);
                *i_buf = color_bg;
                for (int i_center = 0; i_center != 3; i_center++)
                {
                    if (distance(centers[i_center], p) < dotR)
                    {
                        *i_buf = color_dot2;
                    }
                }
                if ((ix + iy) < corner_mark_border)
                {
                    *i_buf = color_cm;
                }
                i_buf++;
            }
        }
    } while (0);
    return err;
}

int CreateSquare4(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf)
{
    int err = EXIT_SUCCESS;
    do {
        int area = edge_length * edge_length;
        int cb_alloc = 4*area;
        cv::Vec4b* i_buf = (cv::Vec4b*)(*ppbuf = (unsigned char*)malloc(cb_alloc));
        if (i_buf == nullptr)
        {
            err = EXIT_FAILURE;
            break;
        }

        cv::Point2f centers[4];
        centers[0] = cv::Point2f(
            (conf->relative_margin + conf->relative_dotR) * edge_length,
            (conf->relative_margin + conf->relative_dotR) * edge_length
        );
        centers[1] = cv::Point2f(
            (1.0f - (conf->relative_margin + conf->relative_dotR)) * (edge_length-1),
            (conf->relative_margin + conf->relative_dotR) * edge_length
        );
        centers[2] = cv::Point2f(centers[1].y, centers[1].x);
        centers[3] = cv::Point2f(centers[1].x, centers[1].x);
        float dotR = conf->relative_dotR * edge_length;
        float corner_mark_border = conf->relative_margin * edge_length;
        for (int iy = 0; iy != edge_length; iy++)
        {
            for (int ix = 0; ix != edge_length; ix++)
            {
                cv::Point2f p((float)ix, (float)iy);
                *i_buf = color_bg;
                for (int i_center = 0; i_center != 4; i_center++)
                {
                    if (distance(centers[i_center], p) < dotR)
                    {
                        *i_buf = color_dot2;
                    }
                }
                if ((ix + iy) < corner_mark_border)
                {
                    *i_buf = color_cm;
                }
                i_buf++;
            }
        }
    } while (0);
    return err;
}

int CreateSquare5(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf)
{
    int err = EXIT_SUCCESS;
    do {
        int area = edge_length * edge_length;
        int cb_alloc = 4*area;
        cv::Vec4b* i_buf = (cv::Vec4b*)(*ppbuf = (unsigned char*)malloc(cb_alloc));
        if (i_buf == nullptr)
        {
            err = EXIT_FAILURE;
            break;
        }

        cv::Point2f centers[5];
        centers[0] = cv::Point2f(
            (conf->relative_margin + conf->relative_dotR) * edge_length,
            (conf->relative_margin + conf->relative_dotR) * edge_length
        );
        centers[1] = cv::Point2f(
            (1.0f - (conf->relative_margin + conf->relative_dotR)) * (edge_length-1),
            (conf->relative_margin + conf->relative_dotR) * edge_length
        );
        centers[2] = cv::Point2f(centers[1].y, centers[1].x);
        centers[3] = cv::Point2f(centers[1].x, centers[1].x);
        centers[4] = cv::Point2f(0.5f * edge_length, 0.5f * edge_length);
        float dotR = conf->relative_dotR * edge_length;
        float corner_mark_border = conf->relative_margin * edge_length;
        for (int iy = 0; iy != edge_length; iy++)
        {
            for (int ix = 0; ix != edge_length; ix++)
            {
                cv::Point2f p((float)ix, (float)iy);
                *i_buf = color_bg;
                for (int i_center = 0; i_center != 5; i_center++)
                {
                    if (distance(centers[i_center], p) < dotR)
                    {
                        *i_buf = color_dot2;
                    }
                }
                if ((ix + iy) < corner_mark_border)
                {
                    *i_buf = color_cm;
                }
                i_buf++;
            }
        }
    } while (0);
    return err;
}

int CreateSquare6(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf)
{
    int err = EXIT_SUCCESS;
    do {
        int area = edge_length * edge_length;
        int cb_alloc = 4*area;
        cv::Vec4b* i_buf = (cv::Vec4b*)(*ppbuf = (unsigned char*)malloc(cb_alloc));
        if (i_buf == nullptr)
        {
            err = EXIT_FAILURE;
            break;
        }

        cv::Point2f centers[6];
        centers[0] = cv::Point2f(
            (conf->relative_margin + conf->relative_dotR) * edge_length,
            (conf->relative_margin + conf->relative_dotR) * edge_length
        );
        centers[1] = cv::Point2f(
            (1.0f - (conf->relative_margin + conf->relative_dotR)) * (edge_length-1),
            (conf->relative_margin + conf->relative_dotR) * edge_length
        );
        centers[2] = cv::Point2f(centers[1].y, centers[1].x);
        centers[3] = cv::Point2f(centers[1].x, centers[1].x);
        centers[4] = cv::Point2f(0.5f * edge_length, centers[0].y);
        centers[5] = cv::Point2f(0.5f * edge_length, centers[3].y);
        float dotR = conf->relative_dotR * edge_length;
        float corner_mark_border = conf->relative_margin * edge_length;
        for (int iy = 0; iy != edge_length; iy++)
        {
            for (int ix = 0; ix != edge_length; ix++)
            {
                cv::Point2f p((float)ix, (float)iy);
                *i_buf = color_bg;
                for (int i_center = 0; i_center != 6; i_center++)
                {
                    if (distance(centers[i_center], p) < dotR)
                    {
                        *i_buf = color_dot2;
                    }
                }
                if ((ix + iy) < corner_mark_border)
                {
                    *i_buf = color_cm;
                }
                i_buf++;
            }
        }
    } while (0);
    return err;
}

int CreateExpandedSurface(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf)
{
    static const CREATE_DIE_TEXTURE subfuncs[] = {
        CreateSquare1, CreateSquare2, CreateSquare3,
        CreateSquare4, CreateSquare5, CreateSquare6,
    };
    int err = EXIT_SUCCESS;
    do {
        int width = DieTextureWidth(edge_length);
        int height = DieTextureHeight(edge_length);
        int area = width * height;
        int cb_alloc = area * 4;
        cv::Vec4b* i_buf = (cv::Vec4b*)(*ppbuf = (unsigned char*)malloc(cb_alloc));
        for (int i = 0; i != area; i++)
        {
            *i_buf++ = color_bg;
        }
        i_buf = (cv::Vec4b*)*ppbuf;
        const cv::Point2i top_lefts[] = {
            { 0, 2*edge_length }, { 2*edge_length, edge_length}, { edge_length, edge_length },
            { 3*edge_length, edge_length }, { 0, edge_length }, { 0, 0 }
        };
        for (int i = 0; i != ARRAYSIZE(subfuncs); i++)
        {
            unsigned char* subbuf = nullptr;
            if (EXIT_SUCCESS != subfuncs[i](conf, edge_length, &subbuf))
            {
                err = EXIT_FAILURE;
                break;
            }
            const cv::Vec4b* i_src = (const cv::Vec4b*)subbuf;
            for (int iy = 0; iy != edge_length; iy++)
            {
                int dst_linear_index = top_lefts[i].x + (iy + top_lefts[i].y)*width;
                cv::Vec4b* i_dst = i_buf + dst_linear_index;
                for (int ix = 0; ix != edge_length; ix++)
                {
                    *i_dst++ = *i_src++;
                }
            }
            free((void*)subbuf);
        }
    } while (0);
    if (err && *ppbuf)
    {
        free((void*)*ppbuf);
        *ppbuf = nullptr;
    }
    return err;
}

int DieTextureWidth(int edge_length)
{
    return edge_length * 4;
}

int DieTextureHeight(int edge_length)
{
    return edge_length * 3;
}
