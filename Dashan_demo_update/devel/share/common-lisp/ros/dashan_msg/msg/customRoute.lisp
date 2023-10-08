; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude customRoute.msg.html

(cl:defclass <customRoute> (roslisp-msg-protocol:ros-message)
  ((pointIndexes
    :reader pointIndexes
    :initarg :pointIndexes
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (length
    :reader length
    :initarg :length
    :type cl:fixnum
    :initform 0))
)

(cl:defclass customRoute (<customRoute>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <customRoute>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'customRoute)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<customRoute> is deprecated: use dashan_msg-msg:customRoute instead.")))

(cl:ensure-generic-function 'pointIndexes-val :lambda-list '(m))
(cl:defmethod pointIndexes-val ((m <customRoute>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:pointIndexes-val is deprecated.  Use dashan_msg-msg:pointIndexes instead.")
  (pointIndexes m))

(cl:ensure-generic-function 'length-val :lambda-list '(m))
(cl:defmethod length-val ((m <customRoute>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:length-val is deprecated.  Use dashan_msg-msg:length instead.")
  (length m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <customRoute>) ostream)
  "Serializes a message object of type '<customRoute>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'pointIndexes))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'pointIndexes))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'length)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <customRoute>) istream)
  "Deserializes a message object of type '<customRoute>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'pointIndexes) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'pointIndexes)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'length)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<customRoute>)))
  "Returns string type for a message object of type '<customRoute>"
  "dashan_msg/customRoute")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'customRoute)))
  "Returns string type for a message object of type 'customRoute"
  "dashan_msg/customRoute")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<customRoute>)))
  "Returns md5sum for a message object of type '<customRoute>"
  "d188738b8b3c860e29d2f4955ba5b012")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'customRoute)))
  "Returns md5sum for a message object of type 'customRoute"
  "d188738b8b3c860e29d2f4955ba5b012")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<customRoute>)))
  "Returns full string definition for message of type '<customRoute>"
  (cl:format cl:nil "#record robot new route that contains a sequence of points; the data is the index of point~%uint32[] pointIndexes~%uint8 length~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'customRoute)))
  "Returns full string definition for message of type 'customRoute"
  (cl:format cl:nil "#record robot new route that contains a sequence of points; the data is the index of point~%uint32[] pointIndexes~%uint8 length~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <customRoute>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pointIndexes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <customRoute>))
  "Converts a ROS message object to a list"
  (cl:list 'customRoute
    (cl:cons ':pointIndexes (pointIndexes msg))
    (cl:cons ':length (length msg))
))
