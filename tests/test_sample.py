import _nuscenes as nuscenes
from pathlib import Path
import os
import random


def test_sample():
    nusc = nuscenes.Nuscenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.samples, list)
    assert len(nusc.samples) > 0
    sample = random.choice(nusc.samples)
    assert isinstance(sample, nuscenes.Sample)
    assert isinstance(sample.token, str)
    assert sample.token is not None
    assert isinstance(sample.scene_token, str)
    assert sample.scene_token is not None
    assert isinstance(sample.timestamp, int)
    assert isinstance(sample.prev, str)
    assert sample.prev is not None
    assert isinstance(sample.next, str)
    assert sample.next is not None
