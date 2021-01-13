#include "onrobot_gripper.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "OnRobot_Gripper");

    gripper g;

    while (ros::ok()) {

        g.spinner();    

    }
    
return 0;

}
