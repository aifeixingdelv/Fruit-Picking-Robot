; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude SaveMap.msg.html

(cl:defclass <SaveMap> (roslisp-msg-protocol:ros-message)
  ((flag
    :reader flag
    :initarg :flag
    :type cl:integer
    :initform 0))
)

(cl:defclass SaveMap (<SaveMap>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SaveMap>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SaveMap)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<SaveMap> is deprecated: use dashan_msg-msg:SaveMap instead.")))

(cl:ensure-generic-function 'flag-val :lambda-list '(m))
(cl:defmethod flag-val ((m <SaveMap>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:flag-val is deprecated.  Use dashan_msg-msg:flag instead.")
  (flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SaveMap>) ostream)
  "Serializes a message object of type '<SaveMap>"
  (cl:let* ((signed (cl:slot-value msg 'flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SaveMap>) istream)
  "Deserializes a message object of type '<SaveMap>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SaveMap>)))
  "Returns string type for a message object of type '<SaveMap>"
  "dashan_msg/SaveMap")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SaveMap)))
  "Returns string type for a message object of type 'SaveMap"
  "dashan_msg/SaveMap")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SaveMap>)))
  "Returns md5sum for a message object of type '<SaveMap>"
  "aa0dbc5596ec12974ea3a17a045b36e0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SaveMap)))
  "Returns md5sum for a message object of type 'SaveMap"
  "aa0dbc5596ec12974ea3a17a045b36e0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SaveMap>)))
  "Returns full string definition for message of type '<SaveMap>"
  (cl:format cl:nil "int32 flag    #1:save map command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SaveMap)))
  "Returns full string definition for message of type 'SaveMap"
  (cl:format cl:nil "int32 flag    #1:save map command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SaveMap>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SaveMap>))
  "Converts a ROS message object to a list"
  (cl:list 'SaveMap
    (cl:cons ':flag (flag msg))
))
