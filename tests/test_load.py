import _nuscenes as nuscenes
import random


def test_load():
    nusc = nuscenes.Nuscenes(path="./data", version="v1.0-mini", verbose=True)
    assert nusc is not None


def test_attributes():
    nusc = nuscenes.Nuscenes(path="./data", version="v1.0-mini", verbose=True)
    assert isinstance(nusc.attributes, list)
    assert len(nusc.attributes) != 0
    assert isinstance(nusc.attributes[0], nuscenes.Attribute)
    assert isinstance(nusc.attributes[0].token, str)
    assert random.sample(nusc.attributes, 1)[0].token is not None
    assert isinstance(nusc.attributes[0].description, str)
