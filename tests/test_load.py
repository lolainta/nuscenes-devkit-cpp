import _nuscenes as nuscenes


def test_load():
    nusc = nuscenes.Nuscenes(path="./data", version="v1.0-mini", verbose=True)
    assert nusc is not None
