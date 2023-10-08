// Generated by gencpp from file dashan_msg/xyyawdata.msg
// DO NOT EDIT!


#ifndef DASHAN_MSG_MESSAGE_XYYAWDATA_H
#define DASHAN_MSG_MESSAGE_XYYAWDATA_H


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
struct xyyawdata_
{
  typedef xyyawdata_<ContainerAllocator> Type;

  xyyawdata_()
    : flag(0)
    , XValue(0)
    , YValue(0)
    , YAWValue(0)  {
    }
  xyyawdata_(const ContainerAllocator& _alloc)
    : flag(0)
    , XValue(0)
    , YValue(0)
    , YAWValue(0)  {
  (void)_alloc;
    }



   typedef uint8_t _flag_type;
  _flag_type flag;

   typedef int32_t _XValue_type;
  _XValue_type XValue;

   typedef int32_t _YValue_type;
  _YValue_type YValue;

   typedef int32_t _YAWValue_type;
  _YAWValue_type YAWValue;




  typedef boost::shared_ptr< ::dashan_msg::xyyawdata_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dashan_msg::xyyawdata_<ContainerAllocator> const> ConstPtr;

}; // struct xyyawdata_

typedef ::dashan_msg::xyyawdata_<std::allocator<void> > xyyawdata;

typedef boost::shared_ptr< ::dashan_msg::xyyawdata > xyyawdataPtr;
typedef boost::shared_ptr< ::dashan_msg::xyyawdata const> xyyawdataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dashan_msg::xyyawdata_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dashan_msg::xyyawdata_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::dashan_msg::xyyawdata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dashan_msg::xyyawdata_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashan_msg::xyyawdata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashan_msg::xyyawdata_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashan_msg::xyyawdata_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashan_msg::xyyawdata_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dashan_msg::xyyawdata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f741085a90ad3eabdab8909f70ea8a0d";
  }

  static const char* value(const ::dashan_msg::xyyawdata_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf741085a90ad3eabULL;
  static const uint64_t static_value2 = 0xdab8909f70ea8a0dULL;
};

template<class ContainerAllocator>
struct DataType< ::dashan_msg::xyyawdata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dashan_msg/xyyawdata";
  }

  static const char* value(const ::dashan_msg::xyyawdata_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dashan_msg::xyyawdata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 flag\n\
int32 XValue\n\
int32 YValue\n\
int32 YAWValue\n\
\n\
\n\
";
  }

  static const char* value(const ::dashan_msg::xyyawdata_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dashan_msg::xyyawdata_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.flag);
      stream.next(m.XValue);
      stream.next(m.YValue);
      stream.next(m.YAWValue);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct xyyawdata_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dashan_msg::xyyawdata_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dashan_msg::xyyawdata_<ContainerAllocator>& v)
  {
    s << indent << "flag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flag);
    s << indent << "XValue: ";
    Printer<int32_t>::stream(s, indent + "  ", v.XValue);
    s << indent << "YValue: ";
    Printer<int32_t>::stream(s, indent + "  ", v.YValue);
    s << indent << "YAWValue: ";
    Printer<int32_t>::stream(s, indent + "  ", v.YAWValue);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DASHAN_MSG_MESSAGE_XYYAWDATA_H
