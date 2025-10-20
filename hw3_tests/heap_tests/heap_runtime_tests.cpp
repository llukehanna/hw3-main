//
// CS104 Heap runtime tests
//

#include <heap.h>

#include <gtest/gtest.h>

#include <functional>

#include <runtime_evaluator.h>
#include <random_generator.h>

// dimension of heap to use in these tests
#define D_ARY 2

TEST(HeapRuntime, Add)
{

	RuntimeEvaluator evaluator("Heap::push() with m=2", 1, 28, 40, [&](uint64_t numElements, RandomSeed seed)
	{
		Heap<int> heap(D_ARY);

		for(int value = 1; value < static_cast<int>(numElements); ++value) // don't add the first element, 0
		{
			heap.push(value);
		}

		BenchmarkTimer timer;
		// worst case for MinHeap: add the smallest element
		heap.push(0);
		timer.stop();

		return timer.getTime();
	});

	//evaluator.enableDebugging();
	evaluator.setCorrelationThreshold(1.2);
	evaluator.evaluate();

	EXPECT_TRUE(evaluator.meetsComplexity(RuntimeEvaluator::TimeComplexity::LOGARITHMIC));
}

TEST(HeapRuntime, Top)
{

	RuntimeEvaluator evaluator("Heap::top() with m=2", 1, 29, 30, [&](uint64_t numElements, RandomSeed seed)
	{
		Heap<int> heap(D_ARY);

		for(int value = 0; value < static_cast<int>(numElements); ++value)
		{
			heap.push(value);
		}

		BenchmarkTimer timer;
		heap.top();
		timer.stop();

		return timer.getTime();
	});

	//evaluator.enableDebugging();
	evaluator.setCorrelationThreshold(1.2);
	evaluator.evaluate();

	EXPECT_TRUE(evaluator.meetsComplexity(RuntimeEvaluator::TimeComplexity::CONSTANT));
}

TEST(HeapRuntime, Remove)
{

	RuntimeEvaluator evaluator("Heap::remove() with m=2", 1, 28, 30, [&](uint64_t numElements, RandomSeed seed)
	{
		Heap<int> heap(D_ARY);

		for(int value = 0; value < static_cast<int>(numElements); ++value)
		{
			heap.push(value);
		}

		BenchmarkTimer timer;
		heap.pop();
		timer.stop();

		return timer.getTime();
	});

	//evaluator.enableDebugging();
	evaluator.setCorrelationThreshold(1.2);
	evaluator.evaluate();

	EXPECT_TRUE(evaluator.meetsComplexity(RuntimeEvaluator::TimeComplexity::LOGARITHMIC));
}