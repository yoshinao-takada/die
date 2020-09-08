#ifndef GLMUTILS_H_
#define	GLMUTILS_H_
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
namespace GLMUtils
{
	typedef struct {
		float eye[3]; // view camera coordinate
		float lookat[3]; // a target point of the view camera' viewline
		float up[3]; // up vector of the view camera
	} LookAtConf_t, * pLookAtConf_t;
	typedef const LookAtConf_t* pcLookAtConf_t;

	// ProjectionConf_t can be used commonly to glm::ortho and glm::frustum
	typedef struct {
		float left_right[2];
		float bottom_top[2];
		float near_far[2];
	} ProjectionConf_t, * pProjectionConf_t;
	typedef const ProjectionConf_t* pcProjectionConf_t;


}


#endif /* GLMUTILS_H_ */