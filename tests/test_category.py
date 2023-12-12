import _nuscenes as nuscenes
import random


def test_category():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.categories, list)
    assert len(nusc.categories) != 0
    assert isinstance(nusc.categories[0], nuscenes.Category)
    assert isinstance(nusc.categories[0].token, str)
    assert random.sample(nusc.categories, 1)[0].token is not None
    assert isinstance(nusc.categories[0].name, str)
    assert isinstance(nusc.categories[0].description, str)
