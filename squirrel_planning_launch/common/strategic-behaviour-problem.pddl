(define (problem squirrel_emotion_task)
(:domain squirrel_emotion)
(:objects
    box1 box2 - box
    c1 c2 c3 - child
    toy1 toy2 - object
    kenny - robot
    toy1_location near_toy1 toy2_location near_toy2 box1_location near_box1 box2_location near_box2 kenny_waypoint pickup_waypoint child_waypoint - waypoint
)
(:init
    (box_at box1 box1_location)
    (box_at box2 box2_location)
    (gripper_empty kenny)
    (not_busy)
    (object_at toy1 toy1_location)
    (object_at toy2 toy2_location)
    (reachable toy2)
    (robot_at kenny kenny_waypoint)
    (= (arousal c1) 0.1)
    (= (arousal c2) 0.1)
    (= (arousal c3) 0.1)
    (= (dominance c1) 0.1)
    (= (dominance c2) 0.1)
    (= (dominance c3) 0.1)
    (= (pleasure c1) 0.1)
    (= (pleasure c2) 0.1)
    (= (pleasure c3) 0.1)
    (= (reciprocal c1) 0.1)
    (= (reciprocal c2) 0.1)
    (= (reciprocal c3) 0.1)
)
(:goal (and
    (in_box box2 toy1)
    (in_box box1 toy2)
)))
