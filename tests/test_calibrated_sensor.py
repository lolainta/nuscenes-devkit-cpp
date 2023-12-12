import _nuscenes as nuscenes
import random


def test_calibrated_sensor():
    nusc = nuscenes.NuScenes(dataroot="./data", version="v1.0-mini", verbose=False)
    assert isinstance(nusc.calibrated_sensors, list)
    assert len(nusc.calibrated_sensors) > 0
    calibrated_sensor = random.choice(nusc.calibrated_sensors)
    assert isinstance(calibrated_sensor, nuscenes.CalibratedSensor)
    assert isinstance(calibrated_sensor.token, str)
    assert calibrated_sensor.token is not None
    assert isinstance(calibrated_sensor.sensor_token, str)
    assert calibrated_sensor.sensor_token is not None
    assert isinstance(calibrated_sensor.translation, nuscenes.Translation)
    assert isinstance(calibrated_sensor.rotation, nuscenes.Rotation)
