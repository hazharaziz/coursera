# python3

from collections import namedtuple, deque

Request = namedtuple("Request", ["arrived_at", "time_to_process"])
Response = namedtuple("Response", ["was_dropped", "started_at"])


class Buffer:
    def __init__(self, size):
        self.size = size
        self.finish_times = deque()
        self.time = 0

    def process(self, request):

        if (len(self.finish_times) == 0):
            self.finish_times.append(request.arrived_at + request.time_to_process)
            self.time = request.arrived_at + request.time_to_process
            return Response(False, request.arrived_at)
        
        while (len(self.finish_times) > 0 and self.finish_times[0] <= request.arrived_at):
            self.finish_times.popleft()

        if (len(self.finish_times) == self.size):
            return Response(True, -1)

        last_finish_time = 0
        if (len(self.finish_times) == 0):
            last_finish_time = request.arrived_at
        else:
            last_finish_time = self.finish_times[len(self.finish_times) - 1]

        if (last_finish_time < request.arrived_at):
            last_finish_time = request.arrived_at
        
        self.finish_times.append(last_finish_time + request.time_to_process)

        return Response(False, last_finish_time)



def process_requests(requests, buffer):
    responses = []
    for request in requests:
        responses.append(buffer.process(request))
    return responses


def main():
    buffer_size, n_requests = map(int, input().split())
    requests = []
    for _ in range(n_requests):
        arrived_at, time_to_process = map(int, input().split())
        requests.append(Request(arrived_at, time_to_process))

    buffer = Buffer(buffer_size)
    responses = process_requests(requests, buffer)

    for response in responses:
        print(response.started_at if not response.was_dropped else -1)


if __name__ == "__main__":
    main()
