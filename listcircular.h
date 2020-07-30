#ifndef LIST_CIRCULAR_H
#define LIST_CIRCULAR_H

#include <iostream>
#include <vector>

/*!
 * \brief The CircularLinkedNode struct
 */
struct CircularLinkedNode
{
    /*!
     * \brief LinkedNode
     */
    CircularLinkedNode()
    {
        next = nullptr;
        this->data = "";
    }
    /*!
     * \brief LinkedNode
     * \param data
     */
    CircularLinkedNode(const std::string& data)
    {
        this->data = data;
        next = nullptr;
    }

    std::string data = "";
    struct CircularLinkedNode* next = nullptr;
};

/*!
 * \brief The ListCircularDataStructure class
 */
class ListCircularDataStructure
{
public:
    /*!
     * \brief ListCircularDataStructure
     */
    ListCircularDataStructure();

    ~ListCircularDataStructure();

    /*!
     * \brief insertBeforeStart
     * \param data
     */
    void insertBeforeStart(const std::string& data);
    /*!
     * \brief insertAfterStart
     * \param data
     */
    void insertAfterStart(const std::string& data);

    /*!
     * \brief removeBeforeStart
     * \return
     */
    CircularLinkedNode *removeBeforeStart();
    /*!
     * \brief removeAfterStart
     * \return
     */
    CircularLinkedNode *removeAfterStart();

    /*!
     * \brief getElementsAsVector
     * \return
     */
    std::vector<std::string> getElementsAsVector();

private:
    struct CircularLinkedNode* start = nullptr;
};

#endif // LIST_CIRCULAR_H
