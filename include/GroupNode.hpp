#pragma once

#include <vector>
#include "Node.hpp"

namespace starforge {
	class GroupNode: public Node {
	public:
		GroupNode(Node * parent = nullptr);
		virtual ~GroupNode();
		
		void AddChild(Node * child);
		void RemoveChild(Node * child);
		const std::vector<Node *> & GetChildren() const;

	protected:
		std::vector<Node *> m_children;

	};
}