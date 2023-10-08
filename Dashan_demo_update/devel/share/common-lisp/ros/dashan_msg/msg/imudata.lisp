; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude imudata.msg.html

(cl:defclass <imudata> (roslisp-msg-protocol:ros-message)
  ((Temp
    :reader Temp
    :initarg :Temp
    :type cl:float
    :initform 0.0)
   (Ax
    :reader Ax
    :initarg :Ax
    :type cl:float
    :initform 0.0)
   (Ay
    :reader Ay
    :initarg :Ay
    :type cl:float
    :initform 0.0)
   (Az
    :reader Az
    :initarg :Az
    :type cl:float
    :initform 0.0)
   (Gx
    :reader Gx
    :initarg :Gx
    :type cl:float
    :initform 0.0)
   (Gy
    :reader Gy
    :initarg :Gy
    :type cl:float
    :initform 0.0)
   (Gz
    :reader Gz
    :initarg :Gz
    :type cl:float
    :initform 0.0)
   (Yaw
    :reader Yaw
    :initarg :Yaw
    :type cl:float
    :initform 0.0))
)

(cl:defclass imudata (<imudata>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <imudata>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'imudata)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<imudata> is deprecated: use dashan_msg-msg:imudata instead.")))

(cl:ensure-generic-function 'Temp-val :lambda-list '(m))
(cl:defmethod Temp-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Temp-val is deprecated.  Use dashan_msg-msg:Temp instead.")
  (Temp m))

(cl:ensure-generic-function 'Ax-val :lambda-list '(m))
(cl:defmethod Ax-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Ax-val is deprecated.  Use dashan_msg-msg:Ax instead.")
  (Ax m))

(cl:ensure-generic-function 'Ay-val :lambda-list '(m))
(cl:defmethod Ay-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Ay-val is deprecated.  Use dashan_msg-msg:Ay instead.")
  (Ay m))

(cl:ensure-generic-function 'Az-val :lambda-list '(m))
(cl:defmethod Az-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Az-val is deprecated.  Use dashan_msg-msg:Az instead.")
  (Az m))

(cl:ensure-generic-function 'Gx-val :lambda-list '(m))
(cl:defmethod Gx-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Gx-val is deprecated.  Use dashan_msg-msg:Gx instead.")
  (Gx m))

(cl:ensure-generic-function 'Gy-val :lambda-list '(m))
(cl:defmethod Gy-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Gy-val is deprecated.  Use dashan_msg-msg:Gy instead.")
  (Gy m))

(cl:ensure-generic-function 'Gz-val :lambda-list '(m))
(cl:defmethod Gz-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Gz-val is deprecated.  Use dashan_msg-msg:Gz instead.")
  (Gz m))

(cl:ensure-generic-function 'Yaw-val :lambda-list '(m))
(cl:defmethod Yaw-val ((m <imudata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Yaw-val is deprecated.  Use dashan_msg-msg:Yaw instead.")
  (Yaw m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <imudata>) ostream)
  "Serializes a message object of type '<imudata>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Temp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Ax))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Ay))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Az))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Gx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Gy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Gz))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <imudata>) istream)
  "Deserializes a message object of type '<imudata>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Temp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Ax) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Ay) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Az) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Gx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Gy) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Gz) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Yaw) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<imudata>)))
  "Returns string type for a message object of type '<imudata>"
  "dashan_msg/imudata")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'imudata)))
  "Returns string type for a message object of type 'imudata"
  "dashan_msg/imudata")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<imudata>)))
  "Returns md5sum for a message object of type '<imudata>"
  "80dfed3c14e2a11e7333746f7785dbcc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'imudata)))
  "Returns md5sum for a message object of type 'imudata"
  "80dfed3c14e2a11e7333746f7785dbcc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<imudata>)))
  "Returns full string definition for message of type '<imudata>"
  (cl:format cl:nil "float32 Temp~%~%float32 Ax~%float32 Ay~%float32 Az~%~%float32 Gx~%float32 Gy~%float32 Gz~%float32 Yaw~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'imudata)))
  "Returns full string definition for message of type 'imudata"
  (cl:format cl:nil "float32 Temp~%~%float32 Ax~%float32 Ay~%float32 Az~%~%float32 Gx~%float32 Gy~%float32 Gz~%float32 Yaw~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <imudata>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <imudata>))
  "Converts a ROS message object to a list"
  (cl:list 'imudata
    (cl:cons ':Temp (Temp msg))
    (cl:cons ':Ax (Ax msg))
    (cl:cons ':Ay (Ay msg))
    (cl:cons ':Az (Az msg))
    (cl:cons ':Gx (Gx msg))
    (cl:cons ':Gy (Gy msg))
    (cl:cons ':Gz (Gz msg))
    (cl:cons ':Yaw (Yaw msg))
))
