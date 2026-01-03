
#include "issue.hpp"

#include <qjsondocument.h>
#include <qobject.h>

namespace redmine {
Issue::Issue(QObject* parent)
    : QObject(parent), m_estimatedHours(0.0), m_fixedVersionId(), m_isPrivate(), m_priorityId(), m_projectId(),
      m_subprojectId(), m_statusId(), m_trackerId(), m_description("") {}

void Issue::setJsonData(QJsonDocument& jsonData) {
    if (jsonData.isEmpty()) {
        return;
    }
    if (jsonData == m_jsonData) {
        return;
    }
    m_jsonData = jsonData;
    emit jsonDataChanged();
}

int Issue::issueId() const {
    return m_issueId;
}

int Issue::subprojectId() const {
    return m_subprojectId;
}

void Issue::setSubprojectId(int newSubprojectId) {
    if (m_subprojectId == newSubprojectId) {
        return;
    }
    m_subprojectId = newSubprojectId;
    emit subprojectIdChanged();
}

int Issue::projectId() const {
    return m_projectId;
}

void Issue::setProjectId(int newProjectId) {
    if (m_projectId == newProjectId) {
        return;
    }
    m_projectId = newProjectId;
    emit projectIdChanged();
}

int Issue::trackerId() const {
    return m_trackerId;
}

void Issue::setTrackerId(int newTrackerId) {
    if (m_trackerId == newTrackerId) {
        return;
    }
    m_trackerId = newTrackerId;
    emit trackerIdChanged();
}

int Issue::statusId() const {
    return m_statusId;
}

void Issue::setStatusId(int newStatusId) {
    if (m_statusId == newStatusId) {
        return;
    }
    m_statusId = newStatusId;
    emit statusIdChanged();
}

int Issue::priorityId() const {
    return m_priorityId;
}

void Issue::setPriorityId(int newPriorityId) {
    if (m_priorityId == newPriorityId) {
        return;
    }
    m_priorityId = newPriorityId;
    emit priorityIdChanged();
}

QString Issue::subject() const {
    return m_subject;
}

void Issue::setSubject(const QString& newSubject) {
    if (m_subject == newSubject) {
        return;
    }
    m_subject = newSubject;
    emit subjectChanged();
}

QString Issue::description() const {
    return m_description;
}

void Issue::setDescription(const QString& newDescription) {
    if (m_description == newDescription) {
        return;
    }
    m_description = newDescription;
    emit descriptionChanged();
}

int Issue::categoryId() const {
    return m_categoryId;
}

void Issue::setCategoryId(int newCategoryId) {
    if (m_categoryId == newCategoryId) {
        return;
    }
    m_categoryId = newCategoryId;
    emit categoryIdChanged();
}

int Issue::fixedVersionId() const {
    return m_fixedVersionId;
}

void Issue::setFixedVersionId(int newFixedVersionId) {
    if (m_fixedVersionId == newFixedVersionId) {
        return;
    }
    m_fixedVersionId = newFixedVersionId;
    emit fixedVersionIdChanged();
}

int Issue::assignedToId() const {
    return m_assignedToId;
}

void Issue::setAssignedToId(int newAssignedToId) {
    if (m_assignedToId == newAssignedToId) {
        return;
    }
    m_assignedToId = newAssignedToId;
    emit assignedToIdChanged();
}

int Issue::parentIssueId() const {
    return m_parentIssueId;
}

void Issue::setParentIssueId(int newParentIssueId) {
    if (m_parentIssueId == newParentIssueId) {
        return;
    }
    m_parentIssueId = newParentIssueId;
    emit parentIssueIdChanged();
}

QList<int> Issue::watcherUserIds() const {
    return m_watcherUserIds;
}

void Issue::setWatcherUserIds(const QList<int>& newWatcherUserIds) {
    if (m_watcherUserIds == newWatcherUserIds) {
        return;
    }
    m_watcherUserIds = newWatcherUserIds;
    emit watcherUserIdsChanged();
}

bool Issue::isPrivate() const {
    return m_isPrivate;
}

void Issue::setIsPrivate(bool newIsPrivate) {
    if (m_isPrivate == newIsPrivate) {
        return;
    }
    m_isPrivate = newIsPrivate;
    emit isPrivateChanged();
}

float Issue::estimatedHours() const {
    return m_estimatedHours;
}

void Issue::setEstimatedHours(float newEstimatedHours) {
    if (qFuzzyCompare(m_estimatedHours, newEstimatedHours)) {
        return;
    }
    m_estimatedHours = newEstimatedHours;
    emit estimatedHoursChanged();
}

QVariantMap Issue::varianData() const {
    return m_varianData;
}

void Issue::setVarianData(const QVariantMap& newVarianData) {
    if (m_varianData == newVarianData) {
        return;
    }
    m_varianData = newVarianData;
    emit varianDataChanged();
}

QJsonDocument Issue::jsonData() const {
    return m_jsonData;
}

} // namespace redmine
