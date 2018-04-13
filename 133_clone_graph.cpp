/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node) {
            return NULL;
        }
        
        unordered_map<uintptr_t, pair<UndirectedGraphNode*, UndirectedGraphNode*>> pass_nodes;
        vector<UndirectedGraphNode*> one, two;
        vector<UndirectedGraphNode*> &cur_layer = one, &next_layer = two;
        cur_layer.push_back(node);
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        pass_nodes.insert(make_pair(reinterpret_cast<uintptr_t>(node), make_pair(node, new_node)));
        while (cur_layer.size() > 0) {
            for(int i = 0; i < cur_layer.size(); i ++) {
                UndirectedGraphNode* new_parent = pass_nodes[reinterpret_cast<uintptr_t>(cur_layer[i])].second;
                for(int j = 0; j < cur_layer[i]->neighbors.size(); j ++) {
                    if (cur_layer[i]->neighbors[j]) {
                        uintptr_t key = reinterpret_cast<uintptr_t>(cur_layer[i]->neighbors[j]);
                        unordered_map<uintptr_t, pair<UndirectedGraphNode*, UndirectedGraphNode*>>::iterator iter = pass_nodes.find(key);
                        if (iter == pass_nodes.end()) {
                            UndirectedGraphNode* new_child = new UndirectedGraphNode(cur_layer[i]->neighbors[j]->label);
                            iter = pass_nodes.insert(make_pair(key, make_pair(cur_layer[i]->neighbors[j], new_child))).first;
                            next_layer.push_back(cur_layer[i]->neighbors[j]);
                        }
                    
                        new_parent->neighbors.push_back(iter->second.second);
                    }
                }
            }
            
            swap(cur_layer, next_layer);
            next_layer.clear();
        }
        return new_node;
    }
};
