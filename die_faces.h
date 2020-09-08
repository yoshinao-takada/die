#ifndef DIE_FACES_H_
#define DIE_FACES_H_
#ifdef __cplusplus
extern "C" {
#endif
/*!
\brief die surface texture creator configuration
*/
typedef struct {
    float relative_dotR, relative_dotR1;
    float relative_margin;
} DieConf_t, *pDieConf_t;
typedef const DieConf_t *pcDieConf_t;

typedef int (*CREATE_DIE_TEXTURE)(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf);
int CreateSquare1(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf); // square surface of a red dot
int CreateSquare2(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf); // square surface of two black dots
int CreateSquare3(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf); // square surface of three black dots
int CreateSquare4(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf); // square surface of four black dots
int CreateSquare5(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf); // square surface of five black dots
int CreateSquare6(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf); // square surface of six black dots
int CreateExpandedSurface(pcDieConf_t conf, int edge_length, unsigned char* *ppbuf); // merge the six surfaces
int DieTextureWidth(int edge_length); // merged surface width
int DieTextureHeight(int edge_length); // merged surface height
/*
* merged surface image
    +-----+
    |o o o|
    |     |
    |o o o|
    +-----+-----+-----+-----+
    |o   o|o    |    o|o   o|
    |  o  |  o  |     |     |
    |o   o|    o|o    |o   o|
    +-----+-----+-----+-----+
    |     |
    |  O  |
    |     |
    +-----+
*/

#ifdef __cplusplus
}
#endif
#endif /* DIE_FACES_H_ */
