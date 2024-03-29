#pragma once

#include "pcl_util.h"
#include <iostream>
#include <vector>
#include <pcl/segmentation/region_growing.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>//ŷʽ����
#include <pcl/ModelCoefficients.h>
#include <set>

/**
 * Copyright (c) 2024, ������
 * All rights reserved.
 * Auther:������(lzy)
 * Email:lizyforver@outlook.com
 * 20240307,���Ʒָ��
 */


//���嵼����ʽ����C���Եķ�ʽ��������ΪC���Է�ʽ���������ֲ���
#define EXTERNC extern "C"
//����dll������ʽ���˴��ǵ���������ǵ�����Ϊdllinport
#define HEAD EXTERNC __declspec(dllexport)
//�������Լ�����˴�ѡ���׼����Լ����Ҳ������c����Լ��
#define CallingConvention __stdcall

/*
���ܣ���װ�������������ֱ�ӷ��ص������Ľ��
param[in] in_pc Ŀ����ƶ���ָ��
param[in] neighbor_num �����������ݵ����Ŀѡȡ���ʵ��ھ���
param[in] smooth_thresh ��������ֵ
param[in] curva_thresh ������ֵ
param[in] MinClusterSize ��Ϊһ�������С����
param[in] MaxClusterSize ��Ϊһ�������������
����ζ�ŷָ��ĵ�����Ŀ������[MinClusterSize,MaxClusterSize]֮����ܱ����
param[out] out_pc ������ƵĶ���ָ��
*/
HEAD void CallingConvention modifiedGrowRegion(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	int neighbor_num, float smooth_thresh, float curva_thresh,
	int MinClusterSize, int MaxClusterSize,
	pcl::PointCloud<pcl::PointXYZ> * out_pc);

//ԭʼ����������
HEAD void CallingConvention oriGrowRegion(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	int neighbor_num, float smooth_thresh, float curva_thresh,
	int MinClusterSize, int MaxClusterSize,
	vector<pcl::PointIndices> * out_indice);

//ŷʽ����
HEAD void CallingConvention euclideanCluster(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	double distance_thresh, int MinClusterSize, int MaxClusterSize,
	vector<pcl::PointIndices> * out_indice);