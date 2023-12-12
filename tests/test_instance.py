import _nuscenes as nuscenes
from pathlib import Path
import random


def test_instance():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.instances, list)
    assert len(nusc.instances) != 0
    inst = random.sample(nusc.instances, 1)[0]
    assert isinstance(inst, nuscenes.Instance)
    assert isinstance(inst.token, str)
    assert inst.token is not None
    assert isinstance(inst.category_token, str)
    assert isinstance(inst.nbr_annotations, int)
    assert isinstance(inst.first_annotation_token, str)
    assert isinstance(inst.last_annotation_token, str)
