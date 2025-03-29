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