import _nuscenes as nuscenes
from pathlib import Path
import random


def test_log():
    nusc = nuscenes.Nuscenes(path="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.logs, list)
    assert len(nusc.logs) != 0
    assert isinstance(nusc.logs[0], nuscenes.Log)
    assert isinstance(nusc.logs[0].token, str)
    assert random.sample(nusc.logs, 1)[0].token is not None
    assert isinstance(nusc.logs[0].logfile, Path)
    assert isinstance(nusc.logs[0].vehicle, str)
    assert isinstance(nusc.logs[0].date_captured, str)
    assert isinstance(nusc.logs[0].location, nuscenes.Location)
