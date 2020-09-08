#include	"die_faces.h"
#include	<opencv2/imgcodecs.hpp>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>

#define		ENABLE_TEST_APP1
#define		DIE_SURFACE_TEX		IMAGE_DIR	"die_surface.png"
#define		DIE_SCREEN_MAPPED	IMAGE_DIR	"die_mapped1.csv"

// create a texture pattern of a die and save it as a .png file of BGRA pixels
int test_app1_step0()
{
	int err = EXIT_SUCCESS;
	unsigned char* texture_buf = nullptr;
	const DieConf_t conf = { 0.1f, 0.2f, 0.1f };
	const int edge_length = 128;
	static const char* texture_save_path = DIE_SURFACE_TEX;
	do {
		if (EXIT_SUCCESS != (err = CreateExpandedSurface(&conf, edge_length, &texture_buf)))
		{
			break;
		}
		cv::Mat4b cvtexture(DieTextureHeight(edge_length), DieTextureWidth(edge_length), (cv::Vec4b*)texture_buf);
		if (!cv::imwrite(texture_save_path, cvtexture))
		{
			err = EXIT_FAILURE;
			break;
		}
	} while (0);
	if (texture_buf)
	{
		free((void*)texture_buf);
	}
	return err;
}

// map the node coordinates of the five dot surface of the die to the canonical viewing box and save the
// results in a .csv file.
int test_app1_step1()
{
	int err = EXIT_SUCCESS;
	do {
		// create model, view, projection matrices
		glm::mat4 model(1.0f);
		
	} while (0);
	return err;
}

int test_app_main()
{
	int err = EXIT_SUCCESS;
	do {
		if (EXIT_SUCCESS != (err = test_app1_step0()))
		{
			break;
		}
		if (EXIT_SUCCESS != (err = test_app1_step1()))
		{
			break;
		}
	} while (0);
	return err;
}

int main()
{
#if defined(ENABLE_TEST_APP1)
	return test_app1_main();
#else
	return die_main();
#endif
}
