; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude zhishancmd.msg.html

(cl:defclass <zhishancmd> (roslisp-msg-protocol:ros-message)
  ((zhishanCommand
    :reader zhishanCommand
    :initarg :zhishanCommand
    :type cl:fixnum
    :initform 0)
   (autoCharge
    :reader autoCharge
    :initarg :autoCharge
    :type cl:fixnum
    :initform 0)
   (rodControl
    :reader rodControl
    :initarg :rodControl
    :type cl:fixnum
    :initform 0)
   (zhishanPara
    :reader zhishanPara
    :initarg :zhishanPara
    :type cl:fixnum
    :initform 0)
   (zhishanVoice
    :reader zhishanVoice
    :initarg :zhishanVoice
    :type cl:fixnum
    :initform 0))
)

(cl:defclass zhishancmd (<zhishancmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <zhishancmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'zhishancmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<zhishancmd> is deprecated: use dashan_msg-msg:zhishancmd instead.")))

(cl:ensure-generic-function 'zhishanCommand-val :lambda-list '(m))
(cl:defmethod zhishanCommand-val ((m <zhishancmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:zhishanCommand-val is deprecated.  Use dashan_msg-msg:zhishanCommand instead.")
  (zhishanCommand m))

(cl:ensure-generic-function 'autoCharge-val :lambda-list '(m))
(cl:defmethod autoCharge-val ((m <zhishancmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:autoCharge-val is deprecated.  Use dashan_msg-msg:autoCharge instead.")
  (autoCharge m))

(cl:ensure-generic-function 'rodControl-val :lambda-list '(m))
(cl:defmethod rodControl-val ((m <zhishancmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:rodControl-val is deprecated.  Use dashan_msg-msg:rodControl instead.")
  (rodControl m))

(cl:ensure-generic-function 'zhishanPara-val :lambda-list '(m))
(cl:defmethod zhishanPara-val ((m <zhishancmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:zhishanPara-val is deprecated.  Use dashan_msg-msg:zhishanPara instead.")
  (zhishanPara m))

(cl:ensure-generic-function 'zhishanVoice-val :lambda-list '(m))
(cl:defmethod zhishanVoice-val ((m <zhishancmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:zhishanVoice-val is deprecated.  Use dashan_msg-msg:zhishanVoice instead.")
  (zhishanVoice m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <zhishancmd>) ostream)
  "Serializes a message object of type '<zhishancmd>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishanCommand)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'autoCharge)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rodControl)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishanPara)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishanVoice)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <zhishancmd>) istream)
  "Deserializes a message object of type '<zhishancmd>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishanCommand)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'autoCharge)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rodControl)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishanPara)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'zhishanVoice)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<zhishancmd>)))
  "Returns string type for a message object of type '<zhishancmd>"
  "dashan_msg/zhishancmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'zhishancmd)))
  "Returns string type for a message object of type 'zhishancmd"
  "dashan_msg/zhishancmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<zhishancmd>)))
  "Returns md5sum for a message object of type '<zhishancmd>"
  "071fca3f528f7a18348853a91c078ea6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'zhishancmd)))
  "Returns md5sum for a message object of type 'zhishancmd"
  "071fca3f528f7a18348853a91c078ea6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<zhishancmd>)))
  "Returns full string definition for message of type '<zhishancmd>"
  (cl:format cl:nil "#1:save init position 2:save goal position~%#3:navigation goals 4:commision release~%#5:save call position 6:one key call~%#7：set init position 8：voice~%#9：clear navigation goals in yaml~%#10: turn voice ~%#11:touch screen~%#12:miaozhun~%#13:shutdown~%#14:reboot~%#15:turn left~%#16:start run after speaking finished,receive from other node,jixuqianjin~%#17:start speak,send to other node~%#18:patrol is finished~%#19:yuan di deng dai~%#20：dance~%#21:turn right~%#22：select one point and generate four directions points~%uint8 zhishanCommand~%#1:auto charge 2:charge finish 3:send command to serial to prepare charge~%uint8 autoCharge~%#1: rise 2:fall 3:head turn left 4:head turn right 5:arm up 6:arm down 7:dance 8：stop dance~%uint8 rodControl~%# reserve to use ~%# voice8 1：interact 2：play mode 3:play voice 4：interupt 5:patrol and play~%# 6:stop play image after voice is finished 7:patrol and speak~%# turn voice 10: 1:up 2:down~%# touch screen11：1:enable 2:disable~%# turn15and21: the number of PI/4 ~%uint8 zhishanPara~%# voice~%# zhishanCommand 8：voice 5:patrol and play zhishanVoice = number~%uint8 zhishanVoice~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'zhishancmd)))
  "Returns full string definition for message of type 'zhishancmd"
  (cl:format cl:nil "#1:save init position 2:save goal position~%#3:navigation goals 4:commision release~%#5:save call position 6:one key call~%#7：set init position 8：voice~%#9：clear navigation goals in yaml~%#10: turn voice ~%#11:touch screen~%#12:miaozhun~%#13:shutdown~%#14:reboot~%#15:turn left~%#16:start run after speaking finished,receive from other node,jixuqianjin~%#17:start speak,send to other node~%#18:patrol is finished~%#19:yuan di deng dai~%#20：dance~%#21:turn right~%#22：select one point and generate four directions points~%uint8 zhishanCommand~%#1:auto charge 2:charge finish 3:send command to serial to prepare charge~%uint8 autoCharge~%#1: rise 2:fall 3:head turn left 4:head turn right 5:arm up 6:arm down 7:dance 8：stop dance~%uint8 rodControl~%# reserve to use ~%# voice8 1：interact 2：play mode 3:play voice 4：interupt 5:patrol and play~%# 6:stop play image after voice is finished 7:patrol and speak~%# turn voice 10: 1:up 2:down~%# touch screen11：1:enable 2:disable~%# turn15and21: the number of PI/4 ~%uint8 zhishanPara~%# voice~%# zhishanCommand 8：voice 5:patrol and play zhishanVoice = number~%uint8 zhishanVoice~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <zhishancmd>))
  (cl:+ 0
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <zhishancmd>))
  "Converts a ROS message object to a list"
  (cl:list 'zhishancmd
    (cl:cons ':zhishanCommand (zhishanCommand msg))
    (cl:cons ':autoCharge (autoCharge msg))
    (cl:cons ':rodControl (rodControl msg))
    (cl:cons ':zhishanPara (zhishanPara msg))
    (cl:cons ':zhishanVoice (zhishanVoice msg))
))
