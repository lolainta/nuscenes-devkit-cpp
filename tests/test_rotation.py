import _nuscenes as nuscenes
import random


def test_rotation():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.ego_positions, list)
    assert len(nusc.ego_positions) != 0
    ego_pose = random.sample(nusc.ego_positions, 1)[0]
    assert isinstance(ego_pose, nuscenes.EgoPosition)
    rot = ego_pose.rotation
    assert isinstance(rot, nuscenes.Rotation)
    assert isinstance(rot.x, float)
    assert isinstance(rot.y, float)
    assert isinstance(rot.z, float)
    assert isinstance(rot.w, float)
