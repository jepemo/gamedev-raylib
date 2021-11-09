#include "raylib.h"
#include "raymath.h"

Camera
CreateCamera ()
{
  Camera camera = { 0 };
  camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  return camera;
}

int
main (int argc, char **argv)
{

  InitWindow (640, 480, "raylib - voxel basic");

  Camera camera = CreateCamera ();

  Model building = LoadModel ("assets/build.vox");

  // Compute model translation matrix to center model on draw position (0, 0 ,
  // 0)
  BoundingBox bb = GetModelBoundingBox (building);
  Vector3 center = { 0 };
  center.x = bb.min.x + (((bb.max.x - bb.min.x) / 2));
  center.z = bb.min.z + (((bb.max.z - bb.min.z) / 2));

  Matrix matTranslate = MatrixTranslate (-center.x, 0, -center.z);
  building.transform = matTranslate;

  SetCameraMode (camera, CAMERA_ORBITAL);

  SetTargetFPS (10);

  while (!WindowShouldClose ())
    {
      UpdateCamera (&camera);

      BeginDrawing ();
      {
        ClearBackground (RAYWHITE);

        BeginMode3D (camera);
        {
          DrawModel (building, (Vector3){ 0.0, 0.0, 0.0 }, 1.0f, WHITE);
          DrawGrid (10, 1.0f);
        }
        EndMode3D ();
      }
      EndDrawing ();
    }

  UnloadModel (building);
  CloseWindow ();

  return 0;
}