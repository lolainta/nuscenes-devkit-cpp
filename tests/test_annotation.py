import _nuscenes as nuscenes
import random


def test_annotation():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.annotations, list)
    assert len(nusc.annotations) != 0
    ann = random.choice(nusc.annotations)
    assert isinstance(ann, nuscenes.Annotation)
    assert isinstance(ann.token, str)
    assert ann.token is not None
    assert isinstance(ann.sample_token, str)
    assert ann.sample_token is not None
    assert isinstance(ann.instance_token, str)
    assert ann.instance_token is not None
    assert isinstance(ann.attribute_tokens, list)
    assert all(isinstance(t, str) for t in ann.attribute_tokens)
    assert isinstance(ann.visibility_token, str)
    assert ann.visibility_token is not None
    assert isinstance(ann.translation, nuscenes.Translation)
    assert isinstance(ann.rotation, nuscenes.Rotation)
    assert isinstance(ann.size, list)
    assert all(len(a.size) == 3 for a in nusc.annotations)
    assert isinstance(ann.prev, str)
    assert ann.prev is not None
    assert isinstance(ann.next, str)
    assert ann.next is not None
