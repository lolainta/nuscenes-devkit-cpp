import _nuscenes as nuscenes
import random


def test_visibility():
    nusc = nuscenes.Nuscenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.visibilities, list)
    assert len(nusc.visibilities) == 4
    visibilities = sorted(nusc.visibilities, key=lambda x: x.token)

    assert isinstance(visibilities[0], nuscenes.Visibility)
    assert isinstance(visibilities[0].token, str)
    assert visibilities[0].token == "1"
    assert isinstance(visibilities[0].description, str)
    assert (
        visibilities[0].description == "visibility of whole object is between 0 and 40%"
    )
    assert isinstance(visibilities[0].level, str)
    assert visibilities[0].level == "v0-40"

    assert isinstance(visibilities[1], nuscenes.Visibility)
    assert isinstance(visibilities[1].token, str)
    assert visibilities[1].token == "2"
    assert isinstance(visibilities[1].description, str)
    assert (
        visibilities[1].description
        == "visibility of whole object is between 40 and 60%"
    )
    assert isinstance(visibilities[1].level, str)
    assert visibilities[1].level == "v40-60"

    assert isinstance(visibilities[2], nuscenes.Visibility)
    assert isinstance(visibilities[2].token, str)
    assert visibilities[2].token == "3"
    assert isinstance(visibilities[2].description, str)
    assert (
        visibilities[2].description
        == "visibility of whole object is between 60 and 80%"
    )
    assert isinstance(visibilities[2].level, str)
    assert visibilities[2].level == "v60-80"

    assert isinstance(visibilities[3], nuscenes.Visibility)
    assert isinstance(visibilities[3].token, str)
    assert visibilities[3].token == "4"
    assert isinstance(visibilities[3].description, str)
    assert (
        visibilities[3].description
        == "visibility of whole object is between 80 and 100%"
    )
    assert isinstance(visibilities[3].level, str)
    assert visibilities[3].level == "v80-100"
