; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude wheelSpeed.msg.html

(cl:defclass <wheelSpeed> (roslisp-msg-protocol:ros-message)
  ((leftwheel_speed
    :reader leftwheel_speed
    :initarg :leftwheel_speed
    :type cl:float
    :initform 0.0)
   (rightwheel_speed
    :reader rightwheel_speed
    :initarg :rightwheel_speed
    :type cl:float
    :initform 0.0))
)

(cl:defclass wheelSpeed (<wheelSpeed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <wheelSpeed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'wheelSpeed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<wheelSpeed> is deprecated: use dashan_msg-msg:wheelSpeed instead.")))

(cl:ensure-generic-function 'leftwheel_speed-val :lambda-list '(m))
(cl:defmethod leftwheel_speed-val ((m <wheelSpeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:leftwheel_speed-val is deprecated.  Use dashan_msg-msg:leftwheel_speed instead.")
  (leftwheel_speed m))

(cl:ensure-generic-function 'rightwheel_speed-val :lambda-list '(m))
(cl:defmethod rightwheel_speed-val ((m <wheelSpeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:rightwheel_speed-val is deprecated.  Use dashan_msg-msg:rightwheel_speed instead.")
  (rightwheel_speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <wheelSpeed>) ostream)
  "Serializes a message object of type '<wheelSpeed>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'leftwheel_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rightwheel_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <wheelSpeed>) istream)
  "Deserializes a message object of type '<wheelSpeed>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'leftwheel_speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rightwheel_speed) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<wheelSpeed>)))
  "Returns string type for a message object of type '<wheelSpeed>"
  "dashan_msg/wheelSpeed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'wheelSpeed)))
  "Returns string type for a message object of type 'wheelSpeed"
  "dashan_msg/wheelSpeed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<wheelSpeed>)))
  "Returns md5sum for a message object of type '<wheelSpeed>"
  "a9d95faf9204c76e50e85451b2bd65f4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'wheelSpeed)))
  "Returns md5sum for a message object of type 'wheelSpeed"
  "a9d95faf9204c76e50e85451b2bd65f4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<wheelSpeed>)))
  "Returns full string definition for message of type '<wheelSpeed>"
  (cl:format cl:nil "float32 leftwheel_speed~%float32 rightwheel_speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'wheelSpeed)))
  "Returns full string definition for message of type 'wheelSpeed"
  (cl:format cl:nil "float32 leftwheel_speed~%float32 rightwheel_speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <wheelSpeed>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <wheelSpeed>))
  "Converts a ROS message object to a list"
  (cl:list 'wheelSpeed
    (cl:cons ':leftwheel_speed (leftwheel_speed msg))
    (cl:cons ':rightwheel_speed (rightwheel_speed msg))
))
