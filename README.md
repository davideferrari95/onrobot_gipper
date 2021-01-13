# onrobot_gripper

Library that allow to use the OnRobot RG2 Gripper with the URe Manipulator Series.

## Getting Started

### Dependencies

 * fmauch_universal_robot
    ```git clone https://github.com/fmauch/universal_robot.git```
&nbsp;
 * Universal_Robots_ROS_Driver
    ```git clone https://github.com/UniversalRobots/Universal_Robots_ROS_Driver.git```

## Running the tests

Launch the node:

```roslaunch onrobot_gripper onrobot_gripper.launch```

Include the library into your node:

```#include "onrobot_gripper.h"```

## Commands

The gripper can be controlled using the service "/OnRobot_RG2_Gripper/command".
It has 2 state (open/close) and 2 velocities (fast/slow), controlled by two bool variables "open_close" and "fast_slow".

OPEN &nbsp;=&nbsp; 0 &nbsp;|&nbsp; CLOSE &nbsp;=&nbsp; 1
&nbsp;
FAST &nbsp;&nbsp;=&nbsp; 0 &nbsp;|&nbsp; SLOW &nbsp;&nbsp;&nbsp;=&nbsp; 1

```rosservice call /OnRobot_RG2_Gripper/command "open_close: true fast_slow: true"```

## Version

* **ROS:** Melodic+

## Authors

* **Davide Ferrari**

