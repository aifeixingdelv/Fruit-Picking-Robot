# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dashan_msg/wheelSpeed.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class wheelSpeed(genpy.Message):
  _md5sum = "a9d95faf9204c76e50e85451b2bd65f4"
  _type = "dashan_msg/wheelSpeed"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32 leftwheel_speed
float32 rightwheel_speed
"""
  __slots__ = ['leftwheel_speed','rightwheel_speed']
  _slot_types = ['float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       leftwheel_speed,rightwheel_speed

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(wheelSpeed, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.leftwheel_speed is None:
        self.leftwheel_speed = 0.
      if self.rightwheel_speed is None:
        self.rightwheel_speed = 0.
    else:
      self.leftwheel_speed = 0.
      self.rightwheel_speed = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2f.pack(_x.leftwheel_speed, _x.rightwheel_speed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.leftwheel_speed, _x.rightwheel_speed,) = _struct_2f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2f.pack(_x.leftwheel_speed, _x.rightwheel_speed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.leftwheel_speed, _x.rightwheel_speed,) = _struct_2f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2f = struct.Struct("<2f")