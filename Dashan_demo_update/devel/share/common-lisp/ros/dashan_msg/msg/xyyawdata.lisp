; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude xyyawdata.msg.html

(cl:defclass <xyyawdata> (roslisp-msg-protocol:ros-message)
  ((flag
    :reader flag
    :initarg :flag
    :type cl:fixnum
    :initform 0)
   (XValue
    :reader XValue
    :initarg :XValue
    :type cl:integer
    :initform 0)
   (YValue
    :reader YValue
    :initarg :YValue
    :type cl:integer
    :initform 0)
   (YAWValue
    :reader YAWValue
    :initarg :YAWValue
    :type cl:integer
    :initform 0))
)

(cl:defclass xyyawdata (<xyyawdata>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <xyyawdata>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'xyyawdata)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<xyyawdata> is deprecated: use dashan_msg-msg:xyyawdata instead.")))

(cl:ensure-generic-function 'flag-val :lambda-list '(m))
(cl:defmethod flag-val ((m <xyyawdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:flag-val is deprecated.  Use dashan_msg-msg:flag instead.")
  (flag m))

(cl:ensure-generic-function 'XValue-val :lambda-list '(m))
(cl:defmethod XValue-val ((m <xyyawdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:XValue-val is deprecated.  Use dashan_msg-msg:XValue instead.")
  (XValue m))

(cl:ensure-generic-function 'YValue-val :lambda-list '(m))
(cl:defmethod YValue-val ((m <xyyawdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:YValue-val is deprecated.  Use dashan_msg-msg:YValue instead.")
  (YValue m))

(cl:ensure-generic-function 'YAWValue-val :lambda-list '(m))
(cl:defmethod YAWValue-val ((m <xyyawdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:YAWValue-val is deprecated.  Use dashan_msg-msg:YAWValue instead.")
  (YAWValue m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <xyyawdata>) ostream)
  "Serializes a message object of type '<xyyawdata>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flag)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'XValue)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'YValue)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'YAWValue)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <xyyawdata>) istream)
  "Deserializes a message object of type '<xyyawdata>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flag)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'XValue) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'YValue) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'YAWValue) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<xyyawdata>)))
  "Returns string type for a message object of type '<xyyawdata>"
  "dashan_msg/xyyawdata")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'xyyawdata)))
  "Returns string type for a message object of type 'xyyawdata"
  "dashan_msg/xyyawdata")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<xyyawdata>)))
  "Returns md5sum for a message object of type '<xyyawdata>"
  "f741085a90ad3eabdab8909f70ea8a0d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'xyyawdata)))
  "Returns md5sum for a message object of type 'xyyawdata"
  "f741085a90ad3eabdab8909f70ea8a0d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<xyyawdata>)))
  "Returns full string definition for message of type '<xyyawdata>"
  (cl:format cl:nil "uint8 flag~%int32 XValue~%int32 YValue~%int32 YAWValue~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'xyyawdata)))
  "Returns full string definition for message of type 'xyyawdata"
  (cl:format cl:nil "uint8 flag~%int32 XValue~%int32 YValue~%int32 YAWValue~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <xyyawdata>))
  (cl:+ 0
     1
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <xyyawdata>))
  "Converts a ROS message object to a list"
  (cl:list 'xyyawdata
    (cl:cons ':flag (flag msg))
    (cl:cons ':XValue (XValue msg))
    (cl:cons ':YValue (YValue msg))
    (cl:cons ':YAWValue (YAWValue msg))
))
