set(GLM_VERSION "0.9.9")
set(GLM_INCLUDE_DIRS "C:/Users/Qi Zhang/OneDrive - IL State University/courses/2019s/IT356_19s/libs/glm-0.9.9.3/glm")

if (NOT CMAKE_VERSION VERSION_LESS "3.0")
    include("${CMAKE_CURRENT_LIST_DIR}/glmTargets.cmake")
endif()
