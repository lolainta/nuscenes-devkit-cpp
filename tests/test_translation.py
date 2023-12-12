import _nuscenes as nuscenes
import random


def test_translation():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.ego_positions, list)
    assert len(nusc.ego_positions) != 0
    ego_pose = random.sample(nusc.ego_positions, 1)[0]
    assert isinstance(ego_pose, nuscenes.EgoPosition)
    trans = ego_pose.translation
    assert isinstance(trans, nuscenes.Translation)
    assert isinstance(trans.x, float)
    assert isinstance(trans.y, float)
    assert isinstance(trans.z, float)
