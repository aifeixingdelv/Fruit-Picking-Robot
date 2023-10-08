; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude ribbontask.msg.html

(cl:defclass <ribbontask> (roslisp-msg-protocol:ros-message)
  ((cmd
    :reader cmd
    :initarg :cmd
    :type cl:fixnum
    :initform 0)
   (senderip
    :reader senderip
    :initarg :senderip
    :type cl:string
    :initform "")
   (from
    :reader from
    :initarg :from
    :type cl:fixnum
    :initform 0)
   (taskid
    :reader taskid
    :initarg :taskid
    :type cl:string
    :initform "")
   (routeid
    :reader routeid
    :initarg :routeid
    :type cl:integer
    :initform 0)
   (pointid
    :reader pointid
    :initarg :pointid
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (size
    :reader size
    :initarg :size
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ribbontask (<ribbontask>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ribbontask>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ribbontask)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<ribbontask> is deprecated: use dashan_msg-msg:ribbontask instead.")))

(cl:ensure-generic-function 'cmd-val :lambda-list '(m))
(cl:defmethod cmd-val ((m <ribbontask>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:cmd-val is deprecated.  Use dashan_msg-msg:cmd instead.")
  (cmd m))

(cl:ensure-generic-function 'senderip-val :lambda-list '(m))
(cl:defmethod senderip-val ((m <ribbontask>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:senderip-val is deprecated.  Use dashan_msg-msg:senderip instead.")
  (senderip m))

(cl:ensure-generic-function 'from-val :lambda-list '(m))
(cl:defmethod from-val ((m <ribbontask>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:from-val is deprecated.  Use dashan_msg-msg:from instead.")
  (from m))

(cl:ensure-generic-function 'taskid-val :lambda-list '(m))
(cl:defmethod taskid-val ((m <ribbontask>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:taskid-val is deprecated.  Use dashan_msg-msg:taskid instead.")
  (taskid m))

(cl:ensure-generic-function 'routeid-val :lambda-list '(m))
(cl:defmethod routeid-val ((m <ribbontask>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:routeid-val is deprecated.  Use dashan_msg-msg:routeid instead.")
  (routeid m))

(cl:ensure-generic-function 'pointid-val :lambda-list '(m))
(cl:defmethod pointid-val ((m <ribbontask>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:pointid-val is deprecated.  Use dashan_msg-msg:pointid instead.")
  (pointid m))

(cl:ensure-generic-function 'size-val :lambda-list '(m))
(cl:defmethod size-val ((m <ribbontask>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:size-val is deprecated.  Use dashan_msg-msg:size instead.")
  (size m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ribbontask>) ostream)
  "Serializes a message object of type '<ribbontask>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cmd)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'senderip))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'senderip))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'from)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'taskid))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'taskid))
  (cl:let* ((signed (cl:slot-value msg 'routeid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'pointid))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'pointid))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'size)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ribbontask>) istream)
  "Deserializes a message object of type '<ribbontask>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cmd)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'senderip) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'senderip) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'from)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'taskid) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'taskid) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'routeid) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'pointid) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'pointid)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'size)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ribbontask>)))
  "Returns string type for a message object of type '<ribbontask>"
  "dashan_msg/ribbontask")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ribbontask)))
  "Returns string type for a message object of type 'ribbontask"
  "dashan_msg/ribbontask")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ribbontask>)))
  "Returns md5sum for a message object of type '<ribbontask>"
  "5baa3f4faea623af8de2b30e03625db3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ribbontask)))
  "Returns md5sum for a message object of type 'ribbontask"
  "5baa3f4faea623af8de2b30e03625db3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ribbontask>)))
  "Returns full string definition for message of type '<ribbontask>"
  (cl:format cl:nil "#req task 1; release task 2~%uint8 cmd~%#senderip~%string senderip~%#from dc or pda~%uint8 from~%#task uuid~%string taskid~%#route id~%int32 routeid~%#pointid of task ~%int32[] pointid~%uint8 size~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ribbontask)))
  "Returns full string definition for message of type 'ribbontask"
  (cl:format cl:nil "#req task 1; release task 2~%uint8 cmd~%#senderip~%string senderip~%#from dc or pda~%uint8 from~%#task uuid~%string taskid~%#route id~%int32 routeid~%#pointid of task ~%int32[] pointid~%uint8 size~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ribbontask>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'senderip))
     1
     4 (cl:length (cl:slot-value msg 'taskid))
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pointid) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ribbontask>))
  "Converts a ROS message object to a list"
  (cl:list 'ribbontask
    (cl:cons ':cmd (cmd msg))
    (cl:cons ':senderip (senderip msg))
    (cl:cons ':from (from msg))
    (cl:cons ':taskid (taskid msg))
    (cl:cons ':routeid (routeid msg))
    (cl:cons ':pointid (pointid msg))
    (cl:cons ':size (size msg))
))
