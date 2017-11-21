#include <cstdlib>

#include <ros/ros.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/CommandTOL.h>
#include <mavros_msgs/SetMode.h>

int main(int argc, char **argv)
{

    int rate = 10;

    ros::init(argc, argv, "mavros_takeoff");
    ros::NodeHandle n;

    ros::Rate r(rate);

    ros::ServiceClient cl = n.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
    mavros_msgs::SetMode srv_setMode;

    ROS_INFO_STREAM("Changing to GUIDED mode.");

    ////////////////////////////////////////////
    /////////////////GUIDED/////////////////////
    ////////////////////////////////////////////
    srv_setMode.request.base_mode = 0;
    srv_setMode.request.custom_mode = "GUIDED";
    if(cl.call(srv_setMode)){
        ROS_ERROR("setmode send ok %d value:", srv_setMode.response.success);
    }else{
        ROS_ERROR("Failed SetMode");
        return -1;
    }

    ROS_INFO_STREAM("Changing to LOITER mode.");

    ////////////////////////////////////////////
    /////////////////LOITER/////////////////////
    ////////////////////////////////////////////
    srv_setMode.request.base_mode = 0;
    srv_setMode.request.custom_mode = "LOITER";
    if(cl.call(srv_setMode)){
        ROS_ERROR("setmode send ok %d value:", srv_setMode.response.success);
    }else{
        ROS_ERROR("Failed SetMode");
        return -1;
    }

    ROS_INFO_STREAM("Changing to LAND mode.");

    ////////////////////////////////////////////
    /////////////////LAND///////////////////////
    ////////////////////////////////////////////
    srv_setMode.request.base_mode = 0;
    srv_setMode.request.custom_mode = "LAND";
    if(cl.call(srv_setMode)){
        ROS_ERROR("setmode send ok %d value:", srv_setMode.response.success);
    }else{
        ROS_ERROR("Failed SetMode");
        return -1;
    }

    return 0;
}
