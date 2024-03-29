#include "filter.h"

/*
 * Copyright (c) 2024, ������
 * All rights reserved.
 * Auther:������(lzy)
 * Email:lizyforver@outlook.com
 * 20240307,�����˲�����
 */

//�Ե��ƽ��������²���
HEAD void CallingConvention voxelDownSample(pcl::PointCloud<pcl::PointXYZ> * in_pc, double leaf_size,
	                                        pcl::PointCloud<pcl::PointXYZ> * out_pc)
{
	pcl::VoxelGrid<pcl::PointXYZ> voxel;
	voxel.setInputCloud(in_pc->makeShared());
	voxel.setLeafSize(leaf_size, leaf_size, leaf_size);
	voxel.filter(*out_pc);

}
//�Ե��ƽ��н��������²���
HEAD void CallingConvention approximateVoxelDownSample(pcl::PointCloud<pcl::PointXYZ> * in_pc, double leaf_size,
	                                                   pcl::PointCloud<pcl::PointXYZ> * out_pc)
{
	pcl::ApproximateVoxelGrid<pcl::PointXYZ> avoxel;
	avoxel.setInputCloud(in_pc->makeShared());
	avoxel.setLeafSize(leaf_size, leaf_size, leaf_size);
	avoxel.filter(*out_pc);
}

//�����²���
HEAD void CallingConvention uniformDownSample(pcl::PointCloud<pcl::PointXYZ> * in_pc, double radius,
	pcl::PointCloud<pcl::PointXYZ> * out_pc)
{

	pcl::UniformSampling<pcl::PointXYZ> uniform;
	uniform.setInputCloud(in_pc->makeShared());
	uniform.setRadiusSearch(radius);
	uniform.filter(*out_pc);

}

//ֱͨ�˲�
HEAD void CallingConvention passThroughFilter(pcl::PointCloud<pcl::PointXYZ> * in_pc, char * axis_name,
	float limit_min, float limit_max, int negative,
	pcl::PointCloud<pcl::PointXYZ> * out_pc)
{
	pcl::PassThrough<pcl::PointXYZ> pass;
	pass.setInputCloud(in_pc->makeShared());
	if (negative <= 0)
	{
		pass.setNegative(false);
		pass.setFilterFieldName(axis_name);
		pass.setFilterLimits(limit_min, limit_max);
		pass.filter(*out_pc);
	}
	else
	{
		pass.setNegative(true);
		pass.setFilterFieldName(axis_name);
		pass.setFilterLimits(limit_min, limit_max);
		pass.filter(*out_pc);
	}
}
//ͳ���˲�
HEAD void CallingConvention staFilter(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	int neighbor_num, float thresh,
	pcl::PointCloud<pcl::PointXYZ> * out_pc)
{
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sta;
	sta.setInputCloud(in_pc->makeShared());
	sta.setMeanK(neighbor_num);
	sta.setStddevMulThresh(thresh);
	sta.filter(*out_pc);

}

/*
���ܣ��뾶�˲�������Ⱥ��ȥ��
*/
HEAD void CallingConvention radiusFilter(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	double radius, int num_thresh,
	pcl::PointCloud<pcl::PointXYZ> * out_pc)
{
	pcl::RadiusOutlierRemoval<pcl::PointXYZ> ror;
	ror.setInputCloud(in_pc->makeShared());
	ror.setRadiusSearch(radius);
	ror.setMinNeighborsInRadius(num_thresh);
	ror.filter(*out_pc);
}