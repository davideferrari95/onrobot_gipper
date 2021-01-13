#include "onrobot_gripper.h"


//----------------------------------------------------- CONSTRUCTOR -----------------------------------------------------//

gripper::gripper() {

    // ---- ROS SERVICE SERVERS ---- //
    onrobot_gripper_service = nh.advertiseService("/OnRobot_RG2_Gripper/command", &gripper::OnRobot_Gripper_Service_Callback, this);
 
    // ---- ROS SERVICE CLIENTS ---- //
    setIO_client = nh.serviceClient<ur_msgs::SetIO>("/ur_hardware_interface/set_io");

}


gripper::~gripper() {}


//-------------------------------------------------- SERVICES CALLBACK --------------------------------------------------//

// OPEN = 0, CLOSE = 1 || FAST = 0, SLOW = 1
bool gripper::OnRobot_Gripper_Service_Callback (onrobot_gripper::command_gripper_srv::Request &req, onrobot_gripper::command_gripper_srv::Response &res) {

    Command_Gripper(req.open_close, req.fast_slow);

    res.success = true;
    return true;

}

//----------------------------------------------------- FUNCTIONS -----------------------------------------------------//


bool gripper::Command_Gripper (bool open_close, bool fast_slow) {

    // fun = 1 to set output pin
    setIO_srv.request.fun = 1;
    
    // pin 17 = Tool Digital Opuput 1 (set velocity)
    setIO_srv.request.pin = 17;

    // change pin status, FAST = 0, SLOW = 1
    if (fast_slow) {setIO_srv.request.state = 0.0;}
    else {setIO_srv.request.state = 1.0;}
    
    // Set Velocity
    if (setIO_client.call(setIO_srv)) {}
    else {ROS_ERROR("Failed to Call Service: \"/ur_hardware_interface/set_io\"");}

    // fun = 1 to set output pin
    setIO_srv.request.fun = 1;
    
    // pin 16 = Tool Digital Opuput 0 (open/close)
    setIO_srv.request.pin = 16;

    // change pin status, OPEN = 0, CLOSE = 1
    if (open_close) {setIO_srv.request.state = 0.0;}
    else {setIO_srv.request.state = 1.0;}
    
    // Open / Close Gripper
    if (setIO_client.call(setIO_srv)) {}
    else {ROS_ERROR("Failed to Call Service: \"/ur_hardware_interface/set_io\"");}

}


//------------------------------------------------------- MAIN --------------------------------------------------------//


void gripper::spinner (void) {

    ros::spinOnce();

}
