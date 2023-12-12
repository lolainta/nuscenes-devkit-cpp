import _nuscenes as nuscenes
from pathlib import Path
import os
import random


def test_scene():
    nusc = nuscenes.Nuscenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.scenes, list)
    assert len(nusc.scenes) > 0
    scene = random.choice(nusc.scenes)
    assert isinstance(scene, nuscenes.Scene)
    assert isinstance(scene.token, str)
    assert scene.token is not None
    assert isinstance(scene.log_token, str)
    assert scene.log_token is not None
    assert isinstance(scene.description, str)
    assert isinstance(scene.name, str)
    assert isinstance(scene.first_sample_token, str)
    assert scene.first_sample_token is not None
    assert isinstance(scene.last_sample_token, str)
    assert scene.last_sample_token is not None
    assert isinstance(scene.description, str)
