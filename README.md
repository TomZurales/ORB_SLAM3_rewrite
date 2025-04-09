# ORB_SLAM3 Rewrite
This project is an attempt at a reimplementation of ORB_SLAM 3, built to use modernized c++ practices, improve stability, and encourage hacking on state-of-the-art SLAM systems.

## First Class Citezens
ORB SLAM 3 has several classes which make up the essential "core" of the system. Unfortunately, these elements are obscured by placing every class at the same level.

* Map Points
    * The essential "thing" we are tracking to generate the map and estimate our position
* Key Frames
    * Contain all the map points that can be seen from a specific position.
    * The position of the key frames is optimized to create the best possible map by varying the poses of the key frames
* Map
    * Contains an ordered set of key frames, representing the full trajectory taken by the agent

## Class Heirarchy & Docs
### SLAM Sensor
* Holds transforms between cameras, and between cameras and IMU
* Fields
  * 1 or 2 Cameras
  * Optional IMU
* Functions
  * getSensorData()
    * Returns images for each Camera, and IMU readings from last frame if available
### Camera
* Fields
  * Camera intrinsics
  * Distortion parameters
  * Rectification matrix (stereo only)
* Functions
  * undistortKeyPoints(KeyPoint List)
    * Takes a list of distorted keypoints, and returns a list of undistorted keypoints
### Keypoint (TODO: Rename)
* Fields
  * KeyPoint - CV::KeyPoint
  * Descriptor - CV::Vector
### MapPoint
* Fields
  * Vector3 pose
  * Descriptor List 
  * Best Descriptor
### Image Frame
* Fields
  * Camera
  * Keypoint List
### Frame
* Fields
  * Map Point List
  * Vector3 Position
* Functions
  * fromStereoKeypoints(Image Frame 1, Image Frame 2, )