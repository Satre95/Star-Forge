#include "GroupNode.hpp"

namespace starforge {
	GroupNode::GroupNode(Node * parent) : Node(parent) {

	}

	GroupNode::~GroupNode() {
		for(Node * aNode: m_children)
			delete aNode;
		m_children.clear();
	}

	void GroupNode::AddChild(Node * child) { 
		m_children.push_back(child);
	}
		
	void GroupNode::RemoveChild(Node * child) { 
			m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
		}
		
	const std::vector<Node *> & GroupNode::GetChildren() const { 
		return m_children;
	}
}