# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dashan_msg/xyyawdata.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class xyyawdata(genpy.Message):
  _md5sum = "f741085a90ad3eabdab8909f70ea8a0d"
  _type = "dashan_msg/xyyawdata"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """uint8 flag
int32 XValue
int32 YValue
int32 YAWValue


"""
  __slots__ = ['flag','XValue','YValue','YAWValue']
  _slot_types = ['uint8','int32','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       flag,XValue,YValue,YAWValue

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(xyyawdata, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.flag is None:
        self.flag = 0
      if self.XValue is None:
        self.XValue = 0
      if self.YValue is None:
        self.YValue = 0
      if self.YAWValue is None:
        self.YAWValue = 0
    else:
      self.flag = 0
      self.XValue = 0
      self.YValue = 0
      self.YAWValue = 0

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
      buff.write(_struct_B3i.pack(_x.flag, _x.XValue, _x.YValue, _x.YAWValue))
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
      end += 13
      (_x.flag, _x.XValue, _x.YValue, _x.YAWValue,) = _struct_B3i.unpack(str[start:end])
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
      buff.write(_struct_B3i.pack(_x.flag, _x.XValue, _x.YValue, _x.YAWValue))
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
      end += 13
      (_x.flag, _x.XValue, _x.YValue, _x.YAWValue,) = _struct_B3i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_B3i = struct.Struct("<B3i")
