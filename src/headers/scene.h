//
// Created by harrison on 9/20/2016.
//

#ifndef CS430_PROJ2_RAYCASTER_SCENE_H
#define CS430_PROJ2_RAYCASTER_SCENE_H

#include "vec.h"
#include "image.h"
#include "json.h"

typedef struct {
    double width;
    double height;
    bool animated;
    double startTime;
    double endTime;
    double frameRate;

    double* widthKfs;
    double* heightKfs;
} SceneCamera;
typedef SceneCamera* SceneCameraRef;

typedef struct {
    double radius;
    double* radiusKfs;
} SceneSphere;
typedef SceneSphere* SceneSphereRef;

typedef struct {
    Vector normal;
    Vector* normalKfs;
} ScenePlane;
typedef ScenePlane* ScenePlaneRef;

typedef enum {
    SCENE_OBJECT_CAMERA,
    SCENE_OBJECT_SPHERE,
    SCENE_OBJECT_PLANE
} SceneObjectType;

typedef struct {
    SceneObjectType type;
    Vector pos;
    Vector angle;
    Color color;
    double* tValues;
    int tCount;
    union {
        SceneCamera camera;
        SceneSphere sphere;
        ScenePlane plane;
    } data;
    Vector* posKfs;
    Vector* angleKfs;
    Color* colorKfs;
} SceneObject;
typedef SceneObject* SceneObjectRef;

typedef struct {
    int objectCount;
    SceneObjectRef camera;
    SceneObjectRef objects;
} Scene;
typedef Scene* SceneRef;

/**
 * Builds a scene from a root json object representing a scene
 * @param jsonRoot - The root json object
 * @param sceneOut - The place where the scene will be stored
 * @return 1 if success, 0 if failure
 */
int scene_build(JsonElementRef jsonRoot, SceneRef sceneOut);

int scene_prep_frame(SceneRef sceneOut, double t);

#endif //CS430_PROJ2_RAYCASTER_SCENE_H
