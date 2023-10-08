// Generated by gencpp from file dashan_msg/diagnosis.msg
// DO NOT EDIT!


#ifndef DASHAN_MSG_MESSAGE_DIAGNOSIS_H
#define DASHAN_MSG_MESSAGE_DIAGNOSIS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dashan_msg
{
template <class ContainerAllocator>
struct diagnosis_
{
  typedef diagnosis_<ContainerAllocator> Type;

  diagnosis_()
    : initInfo(0)
    , hardwareInfo(0)
    , Node(0)
    , State(0)
    , Para(0)  {
    }
  diagnosis_(const ContainerAllocator& _alloc)
    : initInfo(0)
    , hardwareInfo(0)
    , Node(0)
    , State(0)
    , Para(0)  {
  (void)_alloc;
    }



   typedef uint8_t _initInfo_type;
  _initInfo_type initInfo;

   typedef uint8_t _hardwareInfo_type;
  _hardwareInfo_type hardwareInfo;

   typedef uint8_t _Node_type;
  _Node_type Node;

   typedef uint8_t _State_type;
  _State_type State;

   typedef uint8_t _Para_type;
  _Para_type Para;




  typedef boost::shared_ptr< ::dashan_msg::diagnosis_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dashan_msg::diagnosis_<ContainerAllocator> const> ConstPtr;

}; // struct diagnosis_

typedef ::dashan_msg::diagnosis_<std::allocator<void> > diagnosis;

typedef boost::shared_ptr< ::dashan_msg::diagnosis > diagnosisPtr;
typedef boost::shared_ptr< ::dashan_msg::diagnosis const> diagnosisConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dashan_msg::diagnosis_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dashan_msg::diagnosis_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dashan_msg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'dashan_msg': ['/home/zhishan/Dashan_demo_update/src/dashan_msg/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dashan_msg::diagnosis_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dashan_msg::diagnosis_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashan_msg::diagnosis_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashan_msg::diagnosis_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashan_msg::diagnosis_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashan_msg::diagnosis_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dashan_msg::diagnosis_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e928f8638651cca003f8f90f1a284ea4";
  }

  static const char* value(const ::dashan_msg::diagnosis_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe928f8638651cca0ULL;
  static const uint64_t static_value2 = 0x03f8f90f1a284ea4ULL;
};

template<class ContainerAllocator>
struct DataType< ::dashan_msg::diagnosis_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dashan_msg/diagnosis";
  }

  static const char* value(const ::dashan_msg::diagnosis_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dashan_msg::diagnosis_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#initial infomation\n\
uint8 initInfo\n\
#0:ok 1:motor\n\
uint8 hardwareInfo\n\
#nodes state 0:ok 1:notok\n\
uint8 Node\n\
uint8 State\n\
uint8 Para\n\
\n\
#navNodeInfo=1\n\
#odomNodeInfo=2\n\
#modeNodeInfo=3\n\
#coreNodeInfo=4\n\
#bringupNodeInfo=5\n\
#diagNodeInfo=6\n\
#serialNodeInfo=7\n\
#lidarNodeInfo=8\n\
#rpcNodeInfo=9\n\
";
  }

  static const char* value(const ::dashan_msg::diagnosis_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dashan_msg::diagnosis_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.initInfo);
      stream.next(m.hardwareInfo);
      stream.next(m.Node);
      stream.next(m.State);
      stream.next(m.Para);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct diagnosis_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dashan_msg::diagnosis_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dashan_msg::diagnosis_<ContainerAllocator>& v)
  {
    s << indent << "initInfo: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.initInfo);
    s << indent << "hardwareInfo: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.hardwareInfo);
    s << indent << "Node: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.Node);
    s << indent << "State: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.State);
    s << indent << "Para: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.Para);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DASHAN_MSG_MESSAGE_DIAGNOSIS_H
