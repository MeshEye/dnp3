/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef __BASE_DATA_TYPES_H_
#define __BASE_DATA_TYPES_H_

#include <cstdint>

namespace opendnp3
{

/**
  Base class shared by all of the DataPoint types.
*/
class Measurement
{
public:

	virtual ~Measurement() {}

	int64_t GetTime() const { return mTime; }
	uint8_t GetQuality() const { return mQuality; }	

	void SetTime(int64_t aTime) { mTime = aTime; }	
	
protected:	
	Measurement() : mQuality(0), mTime(0)
	{}
	
	Measurement(uint8_t aQuality) : mQuality(aQuality), mTime(0) 
	{}

	Measurement(uint8_t aQuality, int64_t aTime) : mQuality(aQuality), mTime(aTime) 
	{}

	uint8_t mQuality;					//	bitfield that stores type specific quality information
	int64_t mTime;						//	timestamp associated with the measurement, -1 if it was never timestamped	
};


/// Common subclass to analogs and counters
template <class T>
class TypedMeasurement : public Measurement
{
public:

	T GetValue() const { return mValue; }	

	typedef T Type;
	
protected:
	
	TypedMeasurement(): Measurement(), mValue(0) {}
	TypedMeasurement(uint8_t aQuality) : Measurement(aQuality), mValue(0) {}
	TypedMeasurement(T value, uint8_t aQuality) : Measurement(aQuality), mValue(value) {}
	TypedMeasurement(T value, uint8_t aQuality, int64_t aTime) : Measurement(aQuality, aTime), mValue(value) {}

private:
	T mValue;	
};

}


#endif
