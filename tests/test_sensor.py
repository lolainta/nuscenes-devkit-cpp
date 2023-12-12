import _nuscenes as nuscenes
import random


def test_sensor():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.sensors, list)
    assert len(nusc.sensors) == 12
    for sensor in nusc.sensors:
        assert isinstance(sensor, nuscenes.Sensor)
        assert isinstance(sensor.token, str)
        assert sensor.token is not None
        assert isinstance(sensor.modality, str)
        assert sensor.modality is not None
        if sensor.modality == "camera":
            assert isinstance(sensor.channel, str)
            assert sensor.channel is not None
            assert sensor.channel in [
                "CAM_FRONT",
                "CAM_FRONT_LEFT",
                "CAM_FRONT_RIGHT",
                "CAM_BACK",
                "CAM_BACK_LEFT",
                "CAM_BACK_RIGHT",
            ]
        elif sensor.modality == "lidar":
            assert isinstance(sensor.channel, str)
            assert sensor.channel is not None
            assert sensor.channel in [
                "LIDAR_TOP",
                "LIDAR_FRONT_LEFT",
                "LIDAR_FRONT_RIGHT",
                "LIDAR_BACK_LEFT",
                "LIDAR_BACK_RIGHT",
            ]
        elif sensor.modality == "radar":
            assert isinstance(sensor.channel, str)
            assert sensor.channel is not None
            assert sensor.channel in [
                "RADAR_FRONT",
                "RADAR_FRONT_LEFT",
                "RADAR_FRONT_RIGHT",
                "RADAR_BACK_LEFT",
                "RADAR_BACK_RIGHT",
            ]
        else:
            assert False
