// Generated by gencpp from file dashan_msg/customRoute.msg
// DO NOT EDIT!


#ifndef DASHAN_MSG_MESSAGE_CUSTOMROUTE_H
#define DASHAN_MSG_MESSAGE_CUSTOMROUTE_H


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
struct customRoute_
{
  typedef customRoute_<ContainerAllocator> Type;

  customRoute_()
    : pointIndexes()
    , length(0)  {
    }
  customRoute_(const ContainerAllocator& _alloc)
    : pointIndexes(_alloc)
    , length(0)  {
  (void)_alloc;
    }



   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _pointIndexes_type;
  _pointIndexes_type pointIndexes;

   typedef uint8_t _length_type;
  _length_type length;




  typedef boost::shared_ptr< ::dashan_msg::customRoute_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dashan_msg::customRoute_<ContainerAllocator> const> ConstPtr;

}; // struct customRoute_

typedef ::dashan_msg::customRoute_<std::allocator<void> > customRoute;

typedef boost::shared_ptr< ::dashan_msg::customRoute > customRoutePtr;
typedef boost::shared_ptr< ::dashan_msg::customRoute const> customRouteConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dashan_msg::customRoute_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dashan_msg::customRoute_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dashan_msg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'dashan_msg': ['/home/zhishan/Dashan_demo_update/src/dashan_msg/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dashan_msg::customRoute_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dashan_msg::customRoute_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashan_msg::customRoute_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashan_msg::customRoute_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashan_msg::customRoute_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashan_msg::customRoute_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dashan_msg::customRoute_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d188738b8b3c860e29d2f4955ba5b012";
  }

  static const char* value(const ::dashan_msg::customRoute_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd188738b8b3c860eULL;
  static const uint64_t static_value2 = 0x29d2f4955ba5b012ULL;
};

template<class ContainerAllocator>
struct DataType< ::dashan_msg::customRoute_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dashan_msg/customRoute";
  }

  static const char* value(const ::dashan_msg::customRoute_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dashan_msg::customRoute_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#record robot new route that contains a sequence of points; the data is the index of point\n\
uint32[] pointIndexes\n\
uint8 length\n\
";
  }

  static const char* value(const ::dashan_msg::customRoute_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dashan_msg::customRoute_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pointIndexes);
      stream.next(m.length);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct customRoute_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dashan_msg::customRoute_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dashan_msg::customRoute_<ContainerAllocator>& v)
  {
    s << indent << "pointIndexes[]" << std::endl;
    for (size_t i = 0; i < v.pointIndexes.size(); ++i)
    {
      s << indent << "  pointIndexes[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.pointIndexes[i]);
    }
    s << indent << "length: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.length);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DASHAN_MSG_MESSAGE_CUSTOMROUTE_H
