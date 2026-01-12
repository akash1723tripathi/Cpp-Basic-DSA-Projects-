// Brute force -- o(n2)

class RecentCounter
{
private:
      vector<int> v;
      int counter = 0;

public:
      RecentCounter() {}

      int ping(int t)
      {
            v.push_back(t);
            counter = 0;
            for (int i = 0; i < v.size(); i++)
            {
                  if (t - 3000 <= v[i] && v[i] <= t)
                  {
                        counter++;
                  }
            }
            return counter;
      }
};

// Optimized -- o(n) using queue

class RecentCounter{
private:
      queue<int> q;

public:
      RecentCounter() {}

      int ping(int t)
      {
            q.push(t);
            while (!q.empty() && q.front() < t - 3000)
            {
                  q.pop();
            }
            return q.size();
      }
};