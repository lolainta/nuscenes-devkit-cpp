import _nuscenes as nuscenes
from pathlib import Path
import os
import random


def test_sample_data():
    nusc = nuscenes.Nuscenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.sample_datas, list)
    assert len(nusc.sample_datas) > 0
    sample_data = random.choice(nusc.sample_datas)
    assert isinstance(sample_data, nuscenes.SampleData)
    assert isinstance(sample_data.token, str)
    assert sample_data.token is not None
    assert isinstance(sample_data.sample_token, str)
    assert sample_data.sample_token is not None
    assert isinstance(sample_data.ego_pose_token, str)
    assert sample_data.ego_pose_token is not None
    assert isinstance(sample_data.calibrated_sensor_token, str)
    assert sample_data.calibrated_sensor_token is not None
    assert isinstance(sample_data.timestamp, int)
    assert isinstance(sample_data.fileformat, str)
    assert isinstance(sample_data.is_key_frame, bool)
    assert isinstance(sample_data.height, int)
    assert isinstance(sample_data.width, int)
    assert isinstance(sample_data.filename, Path)
    assert sample_data.filename is not None
    assert isinstance(sample_data.prev, str)
    assert sample_data.prev is not None
    assert isinstance(sample_data.next, str)
    assert sample_data.next is not None


def test_sample_data_format():
    nusc = nuscenes.Nuscenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert len(nusc.sample_datas) > 0
    for data in nusc.sample_datas:
        if data.fileformat == "pcd":
            assert data.height == 0
            assert data.width == 0
        elif data.fileformat == "jpg":
            assert data.height == 900
            assert data.width == 1600
        else:
            assert False, "Unknown file format"


def test_sample_filename():
    nusc = nuscenes.Nuscenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert len(nusc.sample_datas) > 0
    for data in nusc.sample_datas:
        assert isinstance(data.filename, Path)
        assert data.filename is not None
        fpath = os.path.join(nusc.dataroot, data.filename)
        assert os.path.exists(fpath), f"{fpath} {data.filename}"
