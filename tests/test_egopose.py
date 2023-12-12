import _nuscenes as nuscenes
import random


def test_egopose():
    nusc = nuscenes.Nuscenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.ego_positions, list)
    assert len(nusc.ego_positions) != 0
    assert isinstance(nusc.ego_positions[0], nuscenes.EgoPosition)
    assert isinstance(nusc.ego_positions[0].token, str)
    assert random.sample(nusc.ego_positions, 1)[0].token is not None
    assert isinstance(nusc.ego_positions[0].timestamp, int)
    assert isinstance(nusc.ego_positions[0].rotation, nuscenes.Rotation)
    assert isinstance(nusc.ego_positions[0].translation, nuscenes.Translation)
