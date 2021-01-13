#ifndef ONROBOT_GRIPPER_H
#define ONROBOT_GRIPPER_H

#include <ros/ros.h>

#include "ur_msgs/SetIO.h"
#include "onrobot_gripper/command_gripper_srv.h"

class gripper {

    public:

        gripper();
        ~gripper();
        
        void spinner (void);
    
    private:

        ros::NodeHandle nh;
        
        // ---- ROS SERVICE CLIENTS ---- //
        ros::ServiceClient setIO_client;
        ur_msgs::SetIO setIO_srv;
       
        // ---- ROS SERVICE SERVERS ---- //
        ros::ServiceServer onrobot_gripper_service;
        
        // ---- SERVER CALLBACKS ---- //
        bool OnRobot_Gripper_Service_Callback (onrobot_gripper::command_gripper_srv::Request &req, onrobot_gripper::command_gripper_srv::Response &res);

        bool Command_Gripper (bool open_close, bool fast_slow);


};

#endif /* ONROBOT_GRIPPER_H */