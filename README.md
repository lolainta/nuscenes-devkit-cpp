# NuScenes Software Development Kit in Cpp

## Basic Information

The nuScenes dataset, developed by [Motional](https://motional.com), is a large-scale public dataset for autonomous driving research.
It comprises 1,000 driving scenes in Boston and Singapore, showcasing diverse and challenging scenarios. The dataset includes 1.4 million camera images, 390,000 LIDAR sweeps, 1.4 million RADAR sweeps, and 1.4 million object bounding boxes. Annotations cover 23 object classes and object-level attributes.
The dataset aims to support research in computer vision and autonomous driving, emphasizing the entire sensor suite of autonomous vehicles, making it unique compared to other datasets.
A supplementary dataset, nuScenes-lidarseg, offers lidar semantic segmentation. The dataset's purpose is to facilitate the development of safe autonomous driving technology worldwide.

## Problem to Solve

The Python SDK, while versatile, can be computationally intensive and resource-demanding, especially when handling large-scale datasets. This can result in slower data loading, manipulation, and processing times, which can impede research and development efforts.

## Prospective Users

The C++ SDK for the nuScenes dataset targets a diverse audience, including researchers, algorithm developers, autonomous vehicle manufacturers, robotics engineers, real-time and embedded systems developers, the open-source community, educational institutions, and commercial solutions providers. This SDK serves as a high-performance and efficient tool to support their work in the fields of autonomous driving, computer vision, and machine learning.

## System Architecture

The data are provided with json format. Thus I will chose to use python to read the data first, since disk I/O is the main reason for slowing down this stage. And using python to parse json format file is more convenient, of course.

Then, I will manipulate the data with cpp, include indexing them or process any inquiries when called with pyhton API.

As mentioned above, I will wrap it with Python API in order to support users using python API before.

## API Description

```python
import nuscenes

if __name__ == "__main__":
    nusc = nuscenes.Nuscene(dataroot="/path/to/the/data", version="mini")
    # get scene data by token in scene table
    scene: nuscenes.Scene = nusc.scene("token")
    # same as others
    anno: nuscenes.Annotation = nusc.annotation("token")
    sample: nuscenes.Sample = nusc.sample("token")
    # ...

    # get scene data by index in scene table
    scene: nuscenes.Scene = nusc.scenes[0]
    # same as others
    anno: nuscenes.Annotation = nusc.annotations[0]
    sample: nuscenes.Sample = nusc.samples[0]
    # ...

    # get sample associated with specific scene
    # This sample object will contain informations in sample_data, ego_pose, calibrated_sensor, and timestamp
    sample: nuscenes.Sample = scene.samples
    # get vehicle log associated with specific scene
    log: nuscenes.Log = scene.log
    # get annotation associated with specific sample
    # This annotation object will contain informations in category, attribute, visibility, instance, and sample
    anno: nuscenes.Annotation = sample.annotations
    # get instance associated with specific annotation
    # This instance object will contain informations in category, attribute, visibility, and sample_annotation
    instance: nuscenes.Instance = anno.instance

```



## Engineer Infrastructure

- Containerlized Building Environment
  - [docker](https://www.docker.com)
  - [GNU make](https://www.gnu.org/software/make/manual/make.html)
- Testing Framework
  - [pytest](https://docs.pytest.org/en/7.4.x/index.html) for python
  - [GoogleTest](https://github.com/google/googletest) for C++ (hopefully)
- Documentation
  - [ReadTheDocs](https://about.readthedocs.com/?ref=readthedocs.org) (hopefully)
  - [pydoc](https://docs.python.org/3/library/pydoc.html)
  - Markdown
- Version Control System
  - git
- Continuous Integration
  - [Github Actions](https://github.com/features/actions)

## Schedule 

The development of the C++ SDK for the nuScenes dataset will follow a well-structured timeline, ensuring that key functions are implemented efficiently while allowing for flexibility to accommodate evolving requirements.

- **Week 1 (10/31): Performance Analysis**
  - Conduct an in-depth analysis of the performance of the existing Python SDK to identify specific areas for optimization.

- **Week 2 (11/7): Infrastructure Setup**
  - Establish the necessary engineer infrastructure, including containerized building environments using Docker, GNU Make, and testing frameworks such as Pytest for Python and GoogleTest for C++.

- **Week 3 (11/14): Data Loading and Indexing**
  - Begin implementing core functionalities for data loading and indexing, optimizing these processes for speed and efficiency.

- **Week 4 (11/21): Flextime**
  - Allocate time for unforeseen challenges, fine-tuning of implemented features, and adjustments based on user feedback.

- **Week 5 (11/28): Object Skeleton Definition**
  - Expand the SDK to enable data manipulation in different tables, improving data access and analysis capabilities.
  - Define object skeletons, establishing a framework for future object-related features.
  
- **Week 6 (12/5): Presentation Preparation**
  - Prepare a framework for the presentation, outlining key features and developments achieved up to this point.

- **Week 7 (12/12): Flextime**
  - Allow flexibility for further adjustments, feature enhancements, and addressing any unforeseen challenges or feedback.

- **Week 8 (12/19): Flextime**
  - Allow flexibility for further adjustments, feature enhancements, and addressing any unforeseen challenges or feedback.

## Reference

- [Proposal Template](https://yyc.solvcon.net/en/latest/nsd/project/project_template.html)
- [Nuscenes Official Website](https://www.nuscenes.org)
- [Nuscenes dev-kit in python](https://github.com/nutonomy/nuscenes-devkit)
