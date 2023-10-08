; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude hmiStatus.msg.html

(cl:defclass <hmiStatus> (roslisp-msg-protocol:ros-message)
  ((commLinkState
    :reader commLinkState
    :initarg :commLinkState
    :type cl:fixnum
    :initform 0)
   (buttonState
    :reader buttonState
    :initarg :buttonState
    :type cl:fixnum
    :initform 0)
   (batteryState
    :reader batteryState
    :initarg :batteryState
    :type cl:fixnum
    :initform 0)
   (batteryPercent
    :reader batteryPercent
    :initarg :batteryPercent
    :type cl:fixnum
    :initform 0)
   (temperature
    :reader temperature
    :initarg :temperature
    :type cl:fixnum
    :initform 0)
   (humidity
    :reader humidity
    :initarg :humidity
    :type cl:fixnum
    :initform 0)
   (smogAlert
    :reader smogAlert
    :initarg :smogAlert
    :type cl:fixnum
    :initform 0)
   (pushRodPos
    :reader pushRodPos
    :initarg :pushRodPos
    :type cl:fixnum
    :initform 0)
   (emergentState
    :reader emergentState
    :initarg :emergentState
    :type cl:fixnum
    :initform 0)
   (zhishancmdshow
    :reader zhishancmdshow
    :initarg :zhishancmdshow
    :type cl:fixnum
    :initform 0)
   (pos_x
    :reader pos_x
    :initarg :pos_x
    :type cl:float
    :initform 0.0)
   (pos_y
    :reader pos_y
    :initarg :pos_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass hmiStatus (<hmiStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <hmiStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'hmiStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<hmiStatus> is deprecated: use dashan_msg-msg:hmiStatus instead.")))

(cl:ensure-generic-function 'commLinkState-val :lambda-list '(m))
(cl:defmethod commLinkState-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:commLinkState-val is deprecated.  Use dashan_msg-msg:commLinkState instead.")
  (commLinkState m))

(cl:ensure-generic-function 'buttonState-val :lambda-list '(m))
(cl:defmethod buttonState-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:buttonState-val is deprecated.  Use dashan_msg-msg:buttonState instead.")
  (buttonState m))

(cl:ensure-generic-function 'batteryState-val :lambda-list '(m))
(cl:defmethod batteryState-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:batteryState-val is deprecated.  Use dashan_msg-msg:batteryState instead.")
  (batteryState m))

(cl:ensure-generic-function 'batteryPercent-val :lambda-list '(m))
(cl:defmethod batteryPercent-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:batteryPercent-val is deprecated.  Use dashan_msg-msg:batteryPercent instead.")
  (batteryPercent m))

(cl:ensure-generic-function 'temperature-val :lambda-list '(m))
(cl:defmethod temperature-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:temperature-val is deprecated.  Use dashan_msg-msg:temperature instead.")
  (temperature m))

(cl:ensure-generic-function 'humidity-val :lambda-list '(m))
(cl:defmethod humidity-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:humidity-val is deprecated.  Use dashan_msg-msg:humidity instead.")
  (humidity m))

(cl:ensure-generic-function 'smogAlert-val :lambda-list '(m))
(cl:defmethod smogAlert-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:smogAlert-val is deprecated.  Use dashan_msg-msg:smogAlert instead.")
  (smogAlert m))

(cl:ensure-generic-function 'pushRodPos-val :lambda-list '(m))
(cl:defmethod pushRodPos-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:pushRodPos-val is deprecated.  Use dashan_msg-msg:pushRodPos instead.")
  (pushRodPos m))

(cl:ensure-generic-function 'emergentState-val :lambda-list '(m))
(cl:defmethod emergentState-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:emergentState-val is deprecated.  Use dashan_msg-msg:emergentState instead.")
  (emergentState m))

(cl:ensure-generic-function 'zhishancmdshow-val :lambda-list '(m))
(cl:defmethod zhishancmdshow-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:zhishancmdshow-val is deprecated.  Use dashan_msg-msg:zhishancmdshow instead.")
  (zhishancmdshow m))

(cl:ensure-generic-function 'pos_x-val :lambda-list '(m))
(cl:defmethod pos_x-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:pos_x-val is deprecated.  Use dashan_msg-msg:pos_x instead.")
  (pos_x m))

(cl:ensure-generic-function 'pos_y-val :lambda-list '(m))
(cl:defmethod pos_y-val ((m <hmiStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:pos_y-val is deprecated.  Use dashan_msg-msg:pos_y instead.")
  (pos_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <hmiStatus>) ostream)
  "Serializes a message object of type '<hmiStatus>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'commLinkState)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buttonState)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'batteryState)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'batteryPercent)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'temperature)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'humidity)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'smogAlert)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pushRodPos)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'emergentState)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishancmdshow)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pos_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pos_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <hmiStatus>) istream)
  "Deserializes a message object of type '<hmiStatus>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'commLinkState)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buttonState)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'batteryState)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'batteryPercent)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'temperature)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'humidity)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'smogAlert)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pushRodPos)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'emergentState)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishancmdshow)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pos_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pos_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<hmiStatus>)))
  "Returns string type for a message object of type '<hmiStatus>"
  "dashan_msg/hmiStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'hmiStatus)))
  "Returns string type for a message object of type 'hmiStatus"
  "dashan_msg/hmiStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<hmiStatus>)))
  "Returns md5sum for a message object of type '<hmiStatus>"
  "783462f146126d76e1d0b3fc51dd06bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'hmiStatus)))
  "Returns md5sum for a message object of type 'hmiStatus"
  "783462f146126d76e1d0b3fc51dd06bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<hmiStatus>)))
  "Returns full string definition for message of type '<hmiStatus>"
  (cl:format cl:nil "#communication link state~%uint8 commLinkState~%#button state~%uint8 buttonState~%#battery info~%uint8 batteryState  # 0:normal state; 1:charge state~%uint8 batteryPercent  # left percent 5%-100%~%~%#temperature~%uint8 temperature~%#humidity~%uint8 humidity~%#smog alert~%uint8 smogAlert  #1:alert 	0:no smog~%#push rod pos~%uint8 pushRodPos~%#emergent push button~%uint8 emergentState~%#define CMD_SAVE_INIT_PARA 1~%#define CMD_SAVE_GOAL_PSTN 2 here send the pos_x pos_y~%#define CMD_SEND_GOALS 3 ~%#define CMD_SEND_CURR_PSTN 4~%#define CMD_SAVE_POS 5~%#define CMD_SEND_POS 6~%#define CMD_SET_INIT_POS 7~%#define CMD_VOICE 8~%#define CMD_CLEAR_NAVIGOALS 9~%uint8 zhishancmdshow~%#position show~%float32 pos_x~%float32 pos_y~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'hmiStatus)))
  "Returns full string definition for message of type 'hmiStatus"
  (cl:format cl:nil "#communication link state~%uint8 commLinkState~%#button state~%uint8 buttonState~%#battery info~%uint8 batteryState  # 0:normal state; 1:charge state~%uint8 batteryPercent  # left percent 5%-100%~%~%#temperature~%uint8 temperature~%#humidity~%uint8 humidity~%#smog alert~%uint8 smogAlert  #1:alert 	0:no smog~%#push rod pos~%uint8 pushRodPos~%#emergent push button~%uint8 emergentState~%#define CMD_SAVE_INIT_PARA 1~%#define CMD_SAVE_GOAL_PSTN 2 here send the pos_x pos_y~%#define CMD_SEND_GOALS 3 ~%#define CMD_SEND_CURR_PSTN 4~%#define CMD_SAVE_POS 5~%#define CMD_SEND_POS 6~%#define CMD_SET_INIT_POS 7~%#define CMD_VOICE 8~%#define CMD_CLEAR_NAVIGOALS 9~%uint8 zhishancmdshow~%#position show~%float32 pos_x~%float32 pos_y~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <hmiStatus>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <hmiStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'hmiStatus
    (cl:cons ':commLinkState (commLinkState msg))
    (cl:cons ':buttonState (buttonState msg))
    (cl:cons ':batteryState (batteryState msg))
    (cl:cons ':batteryPercent (batteryPercent msg))
    (cl:cons ':temperature (temperature msg))
    (cl:cons ':humidity (humidity msg))
    (cl:cons ':smogAlert (smogAlert msg))
    (cl:cons ':pushRodPos (pushRodPos msg))
    (cl:cons ':emergentState (emergentState msg))
    (cl:cons ':zhishancmdshow (zhishancmdshow msg))
    (cl:cons ':pos_x (pos_x msg))
    (cl:cons ':pos_y (pos_y msg))
))
