#pragma once
#include <iostream>
#include <pcl/filters/uniform_sampling.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/uniform_sampling.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/approximate_voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/common/common.h>
#include <pcl/common/common_headers.h>


/*
 * Copyright (c) 2024, ������
 * All rights reserved.
 * Auther:������(lzy)
 * Email:lizyforver@outlook.com
 * 20240307,�����˲�����
 */

using namespace std;
//���嵼����ʽ����C���Եķ�ʽ��������ΪC���Է�ʽ���������ֲ���
#define EXTERNC extern "C"
//����dll������ʽ���˴��ǵ���������ǵ�����Ϊdllinport
#define HEAD EXTERNC __declspec(dllexport)
//�������Լ�����˴�ѡ���׼����Լ����Ҳ������c����Լ��
#define CallingConvention __stdcall

/*
���ܣ��Ե��ƽ��������²���
param[in] in_pc Ŀ����ƶ����ָ��
param[in] leaf_size �����²���Ҷ�ӳߴ磬��ֵԽ������������Խϡ��
param[out] out_pc ������ƶ����ָ��
*/
HEAD void CallingConvention voxelDownSample(pcl::PointCloud<pcl::PointXYZ> * in_pc, double leaf_size,
	                                        pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ��Ե��ƽ��н��������²���
param[in] in_pc Ŀ����ƶ����ָ��
param[in] leaf_size �����²���Ҷ�ӳߴ磬��ֵԽ������������Խϡ��
param[out] out_pc ������ƶ����ָ��
*/
HEAD void CallingConvention approximateVoxelDownSample(pcl::PointCloud<pcl::PointXYZ> * in_pc, double leaf_size,
	                                                   pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ��Ե��ƽ��о����²���
param[in] in_pc Ŀ����ƶ����ָ��
param[in] radius �����²����ֱ��ʲ�������ֵԽ������������Խϡ��
param[out] out_pc ������ƶ����ָ��
*/
HEAD void CallingConvention uniformDownSample(pcl::PointCloud<pcl::PointXYZ> * in_pc, double radius,
	                                          pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ��Ե��ƽ���ֱͨ�˲�
param[in] in_pc Ŀ����ƶ����ָ��
param[in] axis_name ѡ�ĸ�����й���
param[in] limit_min �����������Сֵ
param[in] limit_max ������������ֵ
param[in] negative ����Ƿ�����Ϊtrue�������[limit_min,limit_max]֮��ĵ㣬һ��Ϊfalse
param[out] out_pc ������ƶ����ָ��
*/
HEAD void CallingConvention passThroughFilter(pcl::PointCloud<pcl::PointXYZ> * in_pc, char * axis_name,
	                                          float limit_min, float limit_max, int negative,
	                                          pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ�ʹ��ͳ���˲��Ե���ȥ�룬����Ⱥ��ȥ��
param[in] in_x ����������x����
param[in] in_y ����������y����
param[in] in_z ����������z����
param[in] neighbor_num �����������ݵ����Ŀѡȡ���ʵ��ھ���,Ĭ��50
param[in] thresh ���ƽ��������[��-������,�̣�������]֮��ĵ㱻�޳���thresh���Ǧ�
param[out] out_x ���������е��X����
param[out] out_y ���������е��Y����
param[out] out_z ���������е��Z����
*/
HEAD void CallingConvention staFilter(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	                                  int neighbor_num, float thresh,
	                                  pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ��뾶�˲�������Ⱥ��ȥ��
*/
HEAD void CallingConvention radiusFilter(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	                                     double radius, int num_thresh,
	                                     pcl::PointCloud<pcl::PointXYZ> * out_pc);