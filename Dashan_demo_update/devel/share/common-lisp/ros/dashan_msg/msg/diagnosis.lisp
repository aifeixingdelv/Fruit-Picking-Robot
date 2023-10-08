; Auto-generated. Do not edit!


(cl:in-package dashan_msg-msg)


;//! \htmlinclude diagnosis.msg.html

(cl:defclass <diagnosis> (roslisp-msg-protocol:ros-message)
  ((initInfo
    :reader initInfo
    :initarg :initInfo
    :type cl:fixnum
    :initform 0)
   (hardwareInfo
    :reader hardwareInfo
    :initarg :hardwareInfo
    :type cl:fixnum
    :initform 0)
   (Node
    :reader Node
    :initarg :Node
    :type cl:fixnum
    :initform 0)
   (State
    :reader State
    :initarg :State
    :type cl:fixnum
    :initform 0)
   (Para
    :reader Para
    :initarg :Para
    :type cl:fixnum
    :initform 0))
)

(cl:defclass diagnosis (<diagnosis>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <diagnosis>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'diagnosis)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dashan_msg-msg:<diagnosis> is deprecated: use dashan_msg-msg:diagnosis instead.")))

(cl:ensure-generic-function 'initInfo-val :lambda-list '(m))
(cl:defmethod initInfo-val ((m <diagnosis>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:initInfo-val is deprecated.  Use dashan_msg-msg:initInfo instead.")
  (initInfo m))

(cl:ensure-generic-function 'hardwareInfo-val :lambda-list '(m))
(cl:defmethod hardwareInfo-val ((m <diagnosis>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:hardwareInfo-val is deprecated.  Use dashan_msg-msg:hardwareInfo instead.")
  (hardwareInfo m))

(cl:ensure-generic-function 'Node-val :lambda-list '(m))
(cl:defmethod Node-val ((m <diagnosis>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Node-val is deprecated.  Use dashan_msg-msg:Node instead.")
  (Node m))

(cl:ensure-generic-function 'State-val :lambda-list '(m))
(cl:defmethod State-val ((m <diagnosis>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:State-val is deprecated.  Use dashan_msg-msg:State instead.")
  (State m))

(cl:ensure-generic-function 'Para-val :lambda-list '(m))
(cl:defmethod Para-val ((m <diagnosis>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dashan_msg-msg:Para-val is deprecated.  Use dashan_msg-msg:Para instead.")
  (Para m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <diagnosis>) ostream)
  "Serializes a message object of type '<diagnosis>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'initInfo)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hardwareInfo)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Node)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'State)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Para)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <diagnosis>) istream)
  "Deserializes a message object of type '<diagnosis>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'initInfo)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hardwareInfo)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Node)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'State)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Para)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<diagnosis>)))
  "Returns string type for a message object of type '<diagnosis>"
  "dashan_msg/diagnosis")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'diagnosis)))
  "Returns string type for a message object of type 'diagnosis"
  "dashan_msg/diagnosis")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<diagnosis>)))
  "Returns md5sum for a message object of type '<diagnosis>"
  "e928f8638651cca003f8f90f1a284ea4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'diagnosis)))
  "Returns md5sum for a message object of type 'diagnosis"
  "e928f8638651cca003f8f90f1a284ea4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<diagnosis>)))
  "Returns full string definition for message of type '<diagnosis>"
  (cl:format cl:nil "#initial infomation~%uint8 initInfo~%#0:ok 1:motor~%uint8 hardwareInfo~%#nodes state 0:ok 1:notok~%uint8 Node~%uint8 State~%uint8 Para~%~%#navNodeInfo=1~%#odomNodeInfo=2~%#modeNodeInfo=3~%#coreNodeInfo=4~%#bringupNodeInfo=5~%#diagNodeInfo=6~%#serialNodeInfo=7~%#lidarNodeInfo=8~%#rpcNodeInfo=9~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'diagnosis)))
  "Returns full string definition for message of type 'diagnosis"
  (cl:format cl:nil "#initial infomation~%uint8 initInfo~%#0:ok 1:motor~%uint8 hardwareInfo~%#nodes state 0:ok 1:notok~%uint8 Node~%uint8 State~%uint8 Para~%~%#navNodeInfo=1~%#odomNodeInfo=2~%#modeNodeInfo=3~%#coreNodeInfo=4~%#bringupNodeInfo=5~%#diagNodeInfo=6~%#serialNodeInfo=7~%#lidarNodeInfo=8~%#rpcNodeInfo=9~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <diagnosis>))
  (cl:+ 0
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <diagnosis>))
  "Converts a ROS message object to a list"
  (cl:list 'diagnosis
    (cl:cons ':initInfo (initInfo msg))
    (cl:cons ':hardwareInfo (hardwareInfo msg))
    (cl:cons ':Node (Node msg))
    (cl:cons ':State (State msg))
    (cl:cons ':Para (Para msg))
))
