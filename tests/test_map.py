import _nuscenes as nuscenes
from pathlib import Path
import random


def test_map():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.maps, list)
    assert len(nusc.maps) > 0
    nmap = random.choice(nusc.maps)
    assert isinstance(nmap, nuscenes.Map)
    assert isinstance(nmap.token, str)
    assert nmap.token is not None
    assert isinstance(nmap.category, str)
    assert nmap.category is not None
    assert isinstance(nmap.filename, Path)
    assert nmap.filename is not None
    assert isinstance(nmap.log_tokens, list)
    assert all(isinstance(t, str) for t in nmap.log_tokens)
